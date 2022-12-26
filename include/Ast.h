#ifndef __AST_H__
#define __AST_H__

#include <fstream>
#include "define.h"
#include <stack>
#include "Operand.h"
#include "Type.h"

class SymbolEntry;
class Unit;
class Function;
class BasicBlock;
class Instruction;
class IRBuilder; 

class Node {
    private:
        static int counter;  //counter the node sum
        int seq; 
        Node* next;  //pointer tp the next node
    
    protected:
        std::vector<Instruction*> true_list;
        std::vector<Instruction*> false_list;
        static IRBuilder *builder; //builder 是 IRBuilder 类对象，用于传递继承属性，辅助我们进行中间代码生成
        void backPatch(std::vector<Instruction*> &list, BasicBlock*bb);
        std::vector<Instruction*> merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2);

    public:
        Node();
        int getSeq() const{ return seq; }; //to get the seq
        static void setIRBuilder(IRBuilder* ib) { builder = ib; };
        virtual void output(int level) = 0; //output the level
        void setNextNode(Node* node);  //set the next node
        Node* getNextNode() { return next; } // get the next node
        virtual void typeCheck() = 0;
        virtual void genCode() = 0;
        std::vector<Instruction*>& trueList() {return true_list;}
        std::vector<Instruction*>& falseList() {return false_list;}
};

class ExprNode : public Node {
    private:
        int kind; //indicates which kind it is

    protected:
        SymbolEntry* se;  //symbol entry 体现作用域与可见性信息
        Type* type;
        Operand* dst;  // The result of the subtree is stored into dst.

    public:
        ExprNode(SymbolEntry* se, int kind = EXPR_NORMAL): kind(kind), se(se){};
        Operand* getOperand() { return dst; };
        void output(int level);
        virtual int getIntValue() {return -1; };
        virtual float getFloatValue() { return -1; };
        bool isNormalExpr() const {return kind == EXPR_NORMAL; };
        bool isInitValueLIstExpr() const {return kind == EXPR_INITVALUELIST; };
        bool isImplictCastExpr() const { return kind == EXPR_IMPLICTCASTEXPR; };
        bool isUnaryExpr() const {return kind == EXPR_UNARY; }; 
        bool isImplictCastFloatExpr() const { return kind == EXPR_IMPLICTCASTFLOATEXPR; };
        SymbolEntry* getSymbolEntry() const {return se; };
        void genCode();
        virtual Type* getType() {return type;};
        virtual void typeCheck() {return;};
};


//BinaryExpr
class BinaryExpr : public ExprNode{
    private:
        int op;  //indicates the operator
        ExprNode *expr1, *expr2;
    public:
        BinaryExpr(SymbolEntry* se, int op, ExprNode* expr1, ExprNode* expr2);
        void output(int level);
        int getIntValue();
        float getFloatValue();
        void typeCheck();
        void genCode();
};

//UnaryExpr
class UnaryExpr : public ExprNode {
   private:
        int op;
        ExprNode* expr;

   public:
        UnaryExpr(SymbolEntry* se, int op, ExprNode* expr);
        void output(int level);
        int getIntValue();
        float getFloatValue();
        int getOp() const { return op; };
        void typeCheck();
        void setType(Type* type) {this->type = type; };
        void genCode();
};

//Funtion callExpr
class CallExpr : public ExprNode {
   private:
    ExprNode* param;

   public:
    CallExpr(SymbolEntry* se, ExprNode* param = nullptr);
    void output(int level);
    void typeCheck();
    void genCode();
};

//constant expr
class ConstExpr : public ExprNode {
   public:
    ConstExpr(SymbolEntry* se) : ExprNode(se){
        dst = new Operand(se);
        type = se->getType();
    };
    void output(int level);
    int getIntValue();
    float getFloatValue();
    void typeCheck();
    void genCode();
};

//id
class IdExpr : public ExprNode {
    private:
        ExprNode* arrayId = nullptr;  //array id list
        bool left = false;
    
    public:
        IdExpr(SymbolEntry* se, ExprNode* arrayId = nullptr)
            : ExprNode(se), arrayId(arrayId){
                if(se) {
                    type = se->getType();
                    if(type->isInt()) {
                        SymbolEntry* temp = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
                        dst = new Operand(temp);
                    }else if(type->isFloat()) {
                        SymbolEntry* temp = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
                        dst = new Operand(temp);
                    }else if(type->isArray()) {
                        SymbolEntry* temp = new TemporarySymbolEntry(new PointerType(((ArrayType*)type)->getElementType()),SymbolTable::getLabel());
                        dst = new Operand(temp);
                    }
                }
            };
        void output(int level);
        Type* getType();
        int getIntValue();
        float getFloatValue();
        void typeCheck();
        ExprNode* getArrayId() {return arrayId; };
        void genCode();
        bool isLeft() const { return left; };
        void setLeft() { left = true; }
};

//初始化列表
class InitValueListExpr : public ExprNode {
   private:
        ExprNode* expr;
        int childNum;

   public:
        InitValueListExpr(SymbolEntry* se, ExprNode* expr = nullptr)
            : ExprNode(se, EXPR_INITVALUELIST), expr(expr) {
            type =TypeSystem::boolType;
            childNum = 0;
        };
        void output(int level);
        ExprNode* getExpr() const { return expr; };
        void addExpr(ExprNode* expr);
        bool isEmpty() { return childNum == 0; };
        void typeCheck();
        void genCode();
        void fill(); //new add
        bool isFull();
};

class StmtNode : public Node {
    private:
        int kind;
    public:
        StmtNode(int kind = -1) : kind(kind){};
        virtual void typeCheck() = 0;

};

//复合语句
class CompoundStmt : public StmtNode {
    private:
        StmtNode* stmt;

    public:
        CompoundStmt(StmtNode* stmt = nullptr) : stmt(stmt){};
        void output(int level);
        void typeCheck();
        void genCode();
};

//序列节点
class SeqNode : public StmtNode {
    private:
        StmtNode *stmt1, *stmt2;
    
    public:
        SeqNode(StmtNode* stmt1, StmtNode* stmt2) : stmt1(stmt1), stmt2(stmt2){};
        void output(int level);
        void typeCheck();
        void genCode();

};

//用于 int/float to bool
class ImplictCastExpr : public ExprNode {
   private:
    ExprNode* expr;

   public:
    ImplictCastExpr(ExprNode* expr)
        : ExprNode(nullptr, EXPR_IMPLICTCASTEXPR), expr(expr) {
        type = TypeSystem::boolType;
        dst = new Operand(new TemporarySymbolEntry(type, SymbolTable::getLabel()));
    };
    void output(int level);
    ExprNode* getExpr() const { return expr; };
    void typeCheck();
    void genCode();
};

//use to turn int to float
class ImplictCastFloatExpr : public ExprNode {
    private:
        ExprNode* expr;
    public:
        ImplictCastFloatExpr(ExprNode* expr)
            : ExprNode(nullptr, EXPR_IMPLICTCASTFLOATEXPR), expr(expr) {
                type = TypeSystem::floatType;
                dst = new Operand(new TemporarySymbolEntry(type, SymbolTable::getLabel()));
            };
        void output(int level);
        ExprNode* getExpr() const { return expr; };
        void typeCheck();
        void genCode();
};

//声明语句
class DeclStmt : public StmtNode {
    private:
        IdExpr* id;
        ExprNode* expr;

    public:
        DeclStmt(IdExpr* id, ExprNode* expr = nullptr) : id(id), expr(expr){
            if (expr) {
                this->expr = expr;
                if (expr->isInitValueLIstExpr())
                    ((InitValueListExpr*)(this->expr))->fill();
            }
        };
        void output(int level);
        IdExpr* getId() { return id; };
        void typeCheck();
        void genCode();
};

//空语句
class BlankStmt : public StmtNode {
    public:
        BlankStmt(){};
        void output(int level);
        void typeCheck();
        void genCode();
};

//while语句
class WhileStmt : public StmtNode {
   private:
    ExprNode* cond;
    StmtNode* stmt;
    BasicBlock* cond_bb;
    BasicBlock* end_bb;

   public:
    WhileStmt(ExprNode* cond, StmtNode* stmt) : cond(cond), stmt(stmt){
        //printf("[INFO] %s\n", cond->getType()->toStr().c_str());
        if (cond->getType()->isNum() && cond->getType()->getSize() == 32) {
            ImplictCastExpr* temp = new ImplictCastExpr(cond);
            this->cond = temp;
        }
    };
    void output(int level);
    void typeCheck();
    void genCode();
    BasicBlock* get_cond_bb(){return this->cond_bb;};
    BasicBlock* get_end_bb(){return this->end_bb;};
};

//break语句
class BreakStmt : public StmtNode {
    private:
        StmtNode *whileStmt;
   public:
    BreakStmt(){};
    void output(int level);
    void typeCheck();
    void genCode();
    void setWhileStmt(StmtNode* whileStmt){this->whileStmt=whileStmt;};
};

//continue语句
class ContinueStmt : public StmtNode {
    private:
        StmtNode *whileStmt;
    public:
        ContinueStmt(){};
        void output(int level);
        void typeCheck();
        void genCode();
        void setWhileStmt(StmtNode* whileStmt){this->whileStmt=whileStmt;};
};

//if语句
class IfStmt : public StmtNode {
   private:
    ExprNode* cond;
    StmtNode* thenStmt;

   public:
    IfStmt(ExprNode* cond, StmtNode* thenStmt)
        : cond(cond), thenStmt(thenStmt){
            if (cond->getType()->isNum() && cond->getType()->getSize() == 32) {
                ImplictCastExpr* temp = new ImplictCastExpr(cond);
                this->cond = temp;
            }
        };
    void output(int level);
    void typeCheck();
    void genCode();
};

//ifelse语句
class IfElseStmt : public StmtNode {
    private:
        ExprNode* cond;
        StmtNode* thenStmt;
        StmtNode* elseStmt;

    public:
        IfElseStmt(ExprNode* cond, StmtNode* thenStmt, StmtNode* elseStmt)
        : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt){
            // printf("ifelse\n");
            if (cond->getType()->isNum() && cond->getType()->getSize() == 32) {
                ImplictCastExpr* temp = new ImplictCastExpr(cond);
                this->cond = temp;
                // printf("ifelse1\n");
            }
        };
        void output(int level);
        void typeCheck();
        void genCode();
};

//return语句
class ReturnStmt : public StmtNode {
   private:
    ExprNode* retValue;  //return value

   public:
    ReturnStmt(ExprNode* retValue = nullptr) : retValue(retValue){};
    void output(int level);
    void typeCheck();
    void genCode();
};

//assign语句
class AssignStmt : public StmtNode {
   private:
    ExprNode* lval; //left value
    ExprNode* expr;

   public:
    AssignStmt(ExprNode* lval, ExprNode* expr) : lval(lval), expr(expr){
        if(lval->getType()->isFloat() && expr->getType()->isInt()){
            ImplictCastFloatExpr* temp = new ImplictCastFloatExpr(expr);
            this->expr = temp;
        }
    };
    void output(int level);
    void typeCheck();
    void genCode();
};

//表达式语句
class ExprStmt : public StmtNode {
   private:
    ExprNode* expr;

   public:
    ExprStmt(ExprNode* expr) : expr(expr){};
    void output(int level);
    void typeCheck();
    void genCode();
};

//函数定义语句
class FunDefStmt : public StmtNode {
   private:
    SymbolEntry* se;
    // 参数的定义 next连接
    DeclStmt* decl;
    StmtNode* stmt;

   public:
    FunDefStmt(SymbolEntry* se, DeclStmt* decl, StmtNode* stmt)
        : se(se), decl(decl), stmt(stmt){};
    void output(int level);
    void typeCheck();
    SymbolEntry* getSymbolEntry(){return se;};
    void genCode();
};

//整棵语法树
class Ast {
   private:
    Node* root;

   public:
    Ast() { root = nullptr; }
    void setRoot(Node* n) { root = n; }
    void output();
    void typeCheck();
    void genCode(Unit* unit);
};

#endif