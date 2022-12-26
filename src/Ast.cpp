#include "Ast.h"
#include <stack>
#include <iostream>
#include <string>
#include "IRBuilder.h"
#include "Instruction.h"
#include "SymbolTable.h"
#include "Type.h"
#include "Unit.h"
extern Unit unit;

Type* retType = nullptr;
bool isHaveReturn = false;
std::stack<WhileStmt*>whileStack;

extern FILE* yyout;
int Node::counter = 0;
IRBuilder* Node::builder;

Node::Node(){
    seq = counter++;
    next = nullptr;
}

void Node::setNextNode(Node* node) {
    Node* n = this;
    while(n->getNextNode()) {
        n = n->getNextNode();
    }
    if(n==this) {
        this->next = node;
    }else {
        n->setNextNode(node);
    }
}

void Node::backPatch(std::vector<Instruction*> &list, BasicBlock*bb)
{
    for(auto &inst:list)
    {
        if(inst->isCond())
            dynamic_cast<CondBrInstruction*>(inst)->setTrueBranch(bb);
        else if(inst->isUncond())
            dynamic_cast<UncondBrInstruction*>(inst)->setBranch(bb);
    }
}

std::vector<Instruction*> Node::merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2)
{
    std::vector<Instruction*> res(list1);
    res.insert(res.end(), list2.begin(), list2.end());
    return res;
}


void Ast::output() {
    fprintf(yyout, "program\n");
    if (root != nullptr)
        root->output(4);
}

void ExprNode::output(int level) {
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cconst string\ttype:%s\t%s\n", level, ' ', type.c_str(), name.c_str());
}

void BinaryExpr::output(int level) {
    std::string op_str;
    switch (op)
    {
    case OP_ADD:
        op_str = "add";
        break;
    case OP_SUB:
        op_str = "sub";
        break;
    case OP_MUL:
        op_str = "mul";
        break;
    case OP_DIV:
        op_str = "div";
        break;
    case OP_MOD:
        op_str = "mod";
        break;
    case OP_AND:
        op_str = "and";
        break;
    case OP_OR:
        op_str = "or";
        break;
    case OP_LESS:
        op_str = "less";
        break;
    case OP_LESSEQ:
        op_str = "lessequal";
        break;
    case OP_GREATER:
        op_str = "greater";
        break;
    case OP_GREATEREQ:
        op_str = "greaterequal";
        break;
    case OP_EQUAL:
        op_str = "equal";
        break;
    case OP_NOTEQUAL:
        op_str = "notequal";
        break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\ttype: %s\n", level, ' ', op_str.c_str(),se->getType()->toStr().c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

int BinaryExpr::getIntValue() {
    int value;
    int temp1 = expr1->getIntValue();
    int temp2 = expr2->getIntValue();
    switch (op){
        case OP_ADD:
            value = temp1 + temp2;
            break;
        case OP_SUB:
            value = temp1 - temp2;
            break;
        case OP_MUL:
            value = temp1 * temp2;
            break;
        case OP_DIV:
            if(temp2 == 0){
                fprintf(stderr,"[ERROR] The divider is not 0!\n");
            }
            value = temp1 / temp2;
            break;
        case OP_MOD:
            value = temp1 % temp2;
            break;
        case OP_AND:
            value = temp1 && temp2;
            break;
        case OP_OR:
            value = temp1 || temp2;
            break;
        case OP_LESS:
            value = temp1 < temp2;
            break;
        case OP_LESSEQ:
            value = temp1 <= temp2;
            break;
        case OP_GREATER:
            value = temp1 > temp2;
            break;
        case OP_GREATEREQ:
            value = temp1 >= temp2;
            break;
        case OP_EQUAL:
            value = temp1 == temp2;
            break;
        case OP_NOTEQUAL:
            value = temp1 != temp2;
            break;
    }
    return value;
}

float BinaryExpr::getFloatValue() {
    float value;
    float temp1 = expr1->getFloatValue();
    float temp2 = expr2->getFloatValue();
    switch (op) {
        case OP_ADD:
            value = temp1 + temp2;
            break;
        case OP_SUB:
            value = temp1 - temp2;
            break;
        case OP_MUL:
            value = temp1 * temp2;
            break;
        case OP_DIV:
            if(temp2 == 0){
                fprintf(stderr,"[ERROR] The divider is not 0!\n");
            }
            value = temp1 / temp2;
            break;
        case OP_MOD:
            fprintf(stderr, "[ERROR]The float type can't use the mod!\n");
            exit(1);
        case OP_AND:
            value = temp1 && temp2;
            break;
        case OP_OR:
            value = temp1 || temp2;
            break;
        case OP_LESS:
            value = temp1 < temp2;
            break;
        case OP_LESSEQ:
            value = temp1 <= temp2;
            break;
        case OP_GREATER:
            value = temp1 > temp2;
            break;
        case OP_GREATEREQ:
            value = temp1 >= temp2;
            break;
        case OP_EQUAL:
            value = temp1 == temp2;
            break;
        case OP_NOTEQUAL:
            value = temp1 != temp2;
            break;
    }
    return value;
}

void UnaryExpr::output(int level) {
    std::string op_str;

    switch (op)
    {
    case OP_NOT:
        op_str = "not";
        break;
    case OP_SUB:
        op_str = "minus";
        break;
    }
    fprintf(yyout, "%*cUnaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr->output(level + 4);
}

int UnaryExpr::getIntValue(){
    int value;
    switch (op)
    {
    case OP_NOT:
        value = !(expr->getIntValue());
        break;
    case OP_SUB:
        value = -(expr->getIntValue());
        break;
    }
    return value;
}

float UnaryExpr::getFloatValue(){
    float value;
    switch (op)
    {
    case OP_NOT:
        value = !(expr->getFloatValue());
        break;
    case OP_SUB:
        value = -(expr->getFloatValue());
        break;
    }
    return value;
}

void CallExpr::output(int level) {
    std::string name, type;
    int scope;
    name = se->toStr();
    type = se->getType()->toStr();
    scope = ((IdentifierSymbolEntry*)se)->getScope();
    fprintf(yyout, "%*cCallExpr\tfunction name: %s\tscope: %d\n", level, ' ', name.c_str(), scope);
    Node* temp = param; //turn to output the param node
    while (temp) {
        temp->output(level + 4);
        temp = temp->getNextNode();
    }
}

void ConstExpr::output(int level) {
    std::string type, value;
    type = se->getType()->toStr();
    value = se->toStr();
    if(se->getType()->isInt()) {
        fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',value.c_str(), type.c_str());
    }else if(se->getType()->isFloat()){
        fprintf(yyout, "%*cFloatLiteral\tvalue: %s\ttype: %s\n", level, ' ',value.c_str(), type.c_str());
    }
}

int ConstExpr::getIntValue(){
    return ((ConstantSymbolEntry*)se)->getIntValue();
}

float ConstExpr::getFloatValue(){
    return ((ConstantSymbolEntry*)se)->getFloatValue();
}

int IdExpr::getIntValue() {
    return ((IdentifierSymbolEntry*)se)->getIntValue();
}

float IdExpr::getFloatValue() {
    return ((IdentifierSymbolEntry*)se)->getFloatValue();
}

void IdExpr::output(int level) {
    std::string name, type;
    int scope;
    if(se) {
        name = se->toStr();
        type = se->getType()->toStr();
        scope = ((IdentifierSymbolEntry*)se)->getScope();
        fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ', name.c_str(), scope, type.c_str());
        if (arrayId) {
            ExprNode* temp = arrayId;
            int i = 0;
            while (temp) {
                temp->output(level + 4 + 4 * i++);
                temp = (ExprNode*)(temp->getNextNode());
            }
        }
    }
}

void InitValueListExpr::output(int level) {
    std::string type;
    if (se->getType())
        type = se->getType()->toStr();
    fprintf(yyout, "%*cInitValueListExpr\ttype: %s\n", level, ' ',
            type.c_str());
    Node* temp = expr;
    while (temp) {
        temp->output(level + 4);
        temp = temp->getNextNode();
    }
}

void InitValueListExpr::addExpr(ExprNode* expr) {
    if (this->expr == nullptr) {
        assert(childNum == 0);
        childNum++;
        this->expr = expr;
    } else {
        childNum++;
        this->expr->setNextNode(expr);
    }
}

bool InitValueListExpr::isFull() {
    ArrayType* type = (ArrayType*)(this->se->getType());
    return childNum == type->getLength();
}


void CompoundStmt::output(int level) {
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    if (stmt)
        stmt->output(level + 4);
}

void SeqNode::output(int level) {
    stmt1->output(level);
    stmt2->output(level);
}

void DeclStmt::output(int level) {
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    id->output(level + 4);
    if (expr)
        expr->output(level + 4);
    if (this->getNextNode()) {
        this->getNextNode()->output(level);
    }
}

void BlankStmt::output(int level) {
    fprintf(yyout, "%*cBlankStmt\n", level, ' ');
}

void IfStmt::output(int level) {
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void IfElseStmt::output(int level) {
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void WhileStmt::output(int level) {
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    stmt->output(level + 4);
}

void BreakStmt::output(int level) {
    fprintf(yyout, "%*cBreakStmt\n", level, ' ');
}

void ContinueStmt::output(int level) {
    fprintf(yyout, "%*cContinueStmt\n", level, ' ');
}

void ReturnStmt::output(int level) {
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    if (retValue != nullptr)
        retValue->output(level + 4);
}

void AssignStmt::output(int level) {
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');

    lval->output(level + 4);
    expr->output(level + 4);
}

void ExprStmt::output(int level) {
    fprintf(yyout, "%*cExprStmt\n", level, ' ');
    expr->output(level + 4);
}

void FunDefStmt::output(int level) {
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunDefStmt\tfunction name: %s\ttype: %s\n", level,
            ' ', name.c_str(), type.c_str());
    if (decl) {
        decl->output(level + 4);
    }
    stmt->output(level + 4);
}

void ImplictCastExpr::output(int level) {
    fprintf(yyout, "%*cImplictCastExpr\ttype: %s to bool\n", level, ' ',
            expr->getSymbolEntry()->getType()->toStr().c_str());
    this->expr->output(level + 4);

}

void ImplictCastFloatExpr::output(int level) {
    fprintf(yyout, "%*cImplictCastFloatExpr\ttype: %s to float\n", level, ' ',
            expr->getSymbolEntry()->getType()->toStr().c_str());
    this->expr->output(level + 4);
}

//typeCheck
void ContinueStmt::typeCheck(){
    if(!whileStack.empty()){
        setWhileStmt(whileStack.top());
        return;
    }else{
        fprintf(stderr,"[ERROR] Continue is not in While statment!\n");
    }
}
void BreakStmt::typeCheck(){
    if(!whileStack.empty()){
        setWhileStmt(whileStack.top());
        return;
    }else{
        fprintf(stderr,"[ERROR] Break is not in While statment!\n");
    }
}
void WhileStmt::typeCheck(){
    whileStack.push(this);
    if(stmt!=nullptr)
        stmt->typeCheck();
    whileStack.pop();
    return;
}

void BlankStmt::typeCheck(){return;}
void InitValueListExpr::typeCheck(){return;}
void CallExpr::typeCheck(){return;}
void UnaryExpr::typeCheck(){return;}
void ExprStmt::typeCheck(){return;}

void Ast::typeCheck(){
    if(root!=nullptr)
        root->typeCheck();
    return;
}

void FunDefStmt::typeCheck(){
    SymbolEntry* se = this->getSymbolEntry();
    retType = ((FuncType*)(se->getType()))->getRetType();
    StmtNode* stmt = this->stmt;
    if(stmt==nullptr){
        if(retType != TypeSystem::voidType)
            fprintf(stderr,"[ERROR] The non-void Function has not return statement\n");
    }else{
        stmt->typeCheck();
        if(!isHaveReturn && retType!=TypeSystem::voidType)
            fprintf(stderr,"[ERROR] The non-void Function has not return statement\n");
    }
    retType = nullptr;
    isHaveReturn = false;
    return;
}

void BinaryExpr::typeCheck() {return;};
void ConstExpr::typeCheck() {return;};
void ImplictCastExpr::typeCheck(){return;};
void ImplictCastFloatExpr::typeCheck(){return;};
void IdExpr::typeCheck(){return;}; //here re-define error is in parser.y
void IfStmt::typeCheck(){
    if(thenStmt!=nullptr)
        thenStmt->typeCheck();
    return;
}
void IfElseStmt::typeCheck(){
    if(thenStmt!=nullptr)
        thenStmt->typeCheck();
    if(elseStmt!=nullptr)
        elseStmt->typeCheck();
    return;
}
void CompoundStmt::typeCheck(){
    if(stmt!=nullptr)
        stmt->typeCheck();
    return;
}
void SeqNode::typeCheck(){
    if(stmt1!=nullptr){
        stmt1->typeCheck();
    }
    if(stmt2!=nullptr){
        stmt2->typeCheck();
    }
    return;
}
void DeclStmt::typeCheck(){return;}
void AssignStmt::typeCheck(){
    //printf("[INFO] 1\n");
    Type* temp1 = ((IdExpr*)lval)->getType();
    Type* temp2 = expr->getType();
    //printf("[INFO] 1: %s, 2: %s\n",temp1->toStr().c_str(), temp2->toStr().c_str());
    if(((IntType*)temp1)->isConst() || ((FloatType*)temp1)->isConst()){
        fprintf(stderr, "[ERROR] Cannot assign a const \'%s\' value!\n", temp1->toStr().c_str());
        return;
    }else{
        if(temp1->isInt() && !temp2->isInt())
            fprintf(stderr, "[ERROR] Cannot assign a \'%s\' value to \'int\' value!\n", temp1->toStr().c_str());
        if(temp1->isFloat() && !temp2->isNum())
            fprintf(stderr, "[ERROR] Cannot assign a \'%s\' value to \'float\' value!\n", temp2->toStr().c_str());
    }
    //printf("[INFO] 3\n");
    return;
}

void ReturnStmt::typeCheck(){
    isHaveReturn = true;
    //printf("[INFO] 1\n");
    //printf("[INFO] retvalue %d\n", retValue->getIntValue());
    //printf("[INFO] retType %s\n", retType->toStr().c_str());
    if(retValue==nullptr && retType->isVoid()){
        return;
    }
    if(retType==nullptr){
        fprintf(stderr, "[ERROR] Not the right identifier!\n");
        return;
    }
    if(!retValue && !retType->isVoid()){
        fprintf(stderr, "[ERROR] Non-void Function return with no value(type=>\'%s\')!\n", retType->toStr().c_str());
        return;
    }
    if(retValue && retType->isVoid()){
        fprintf(stderr,"[ERROR] \'void\' Function return with a value!\n");
        return;
    }
    if(!retValue || !retValue->getSymbolEntry()){
        return;
    }
    Type* type = retValue->getType();
    if(retType->isFloat()){
        if(!type->isNum())
            fprintf(stderr,"Cannot initialize return object of type \'%s\' with an rvalue of type \'%s\'\n",retType->toStr().c_str(), type->toStr().c_str());
    }else if(retType != type) {
        fprintf(stderr,"Cannot initialize return object of type \'%s\' with an rvalue of type \'%s\'\n",retType->toStr().c_str(), type->toStr().c_str());
    }
    return;
}

Type* IdExpr::getType() {
    //printf("[INFO] gettype 1\n");
    SymbolEntry* se = this->getSymbolEntry();
    ArrayType* tempType = (ArrayType*)type;
    ExprNode* tempNode = arrayId;
    if(!se)
        return TypeSystem::voidType;
    Type* type = se->getType();
    if(arrayId==nullptr){
        //printf("[INFO] gettype 2\n");
        return type;
    }else if(!type->isArray()) {
        fprintf(stderr, "[ERROR] Subscripted value is not an array!\n");
        //printf("[INFO] gettype 3\n");
        return TypeSystem::voidType;
    }else {
        while(!tempType->getElementType()->isNum()) {
            if(!tempNode) {
                return tempType;
            }
            tempNode = (ExprNode*)(tempNode->getNextNode());
            tempType = (ArrayType*)(tempType->getElementType());
        }
        if(!tempNode) {
            fprintf(stderr,"[INFO] Subscripted value is not an array!\n");
            return tempType;
        }else if(tempNode->getNextNode()) {
            fprintf(stderr, "[INFO] Subscripted value is not an array!\n");
            return TypeSystem::voidType;
        }
        //printf("[INFO] gettype 4\n");
    }
    if(tempType->isInt())
        return TypeSystem::intType;
    else
        return TypeSystem::floatType;
    //printf("[INFO] gettype 5\n");
}

//CallExpr check
CallExpr::CallExpr(SymbolEntry* se, ExprNode* param)
    : ExprNode(se), param(param) {
        // do params check
    SymbolEntry* s = se;
    int paramNum = 0;
    ExprNode* temp = param;
    while(temp!=nullptr) {
        paramNum++;
        temp = (ExprNode*)(temp->getNextNode());
    }
    //find the function
    while(s!=nullptr) {
        bool flag = true;
        Type* type = s->getType();
        std::vector<Type*> params = ((FuncType*)type)->getParamsType();
        temp = param;
        //printf("%d | %ld \n",paramNum, params.size());
        if((unsigned int)paramNum==params.size()) {
            for(int i = 0; i < paramNum; i++){
                //printf("[INFO] %s, %s\n",params[i]->toStr().c_str(), temp->getType()->toStr().c_str());
                if(params[i] != temp->getType()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                this->se = s;
                break;
            }
        }
        //printf("[NEXT]\n");
        s = s->getNextSe();
    }
    se = this->se;
    //printf("[INFO] %s\n",se->toStr().c_str());
    if(se!=nullptr){
        Type* type = se->getType();
        this->type = ((FuncType*)type)->getRetType();
        if(!this->type->isVoid()){
            //SymbolEntry* tempSe = new TemporarySymbolEntry(this->type, SymbolTable::getLabel());
            SymbolEntry* se =new TemporarySymbolEntry(this->type, SymbolTable::getLabel());
            dst = new Operand(se);
        }
        std::vector<Type*> params = ((FuncType*)se->getType())->getParamsType();
        temp = param;
        for(auto it = params.begin(); it!=params.end();it++) {
            //printf("[INFO] %s\n", (*it)->toStr().c_str());
            if(temp == nullptr){
                fprintf(stderr, "[ERROR] Too few arguments for function \'%s %s\'\n",se->toStr().c_str(),type->toStr().c_str());
                break;
            }
            else if((*it)->getKind() != temp->getSymbolEntry()->getType()->getKind()){
                fprintf(stderr, "[ERROR] Parameter's type \'%s\' can't convert to \'%s\'\n",temp->getType()->toStr().c_str(),(*it)->toStr().c_str());
            }
            temp = (ExprNode*)(temp->getNextNode());
        }
        if(temp != nullptr) {
            fprintf(stderr, "[ERROR] Too many arguments for function \'%s %s\'\n", se->toStr().c_str(),type->toStr().c_str());
        }
    }
    //this is sysy function!!!
    if (((IdentifierSymbolEntry*)se)->isSysy()) {
        // printf("yes!");
        unit.insertDeclare(se);
    }
}

BinaryExpr::BinaryExpr(SymbolEntry* se,int op,ExprNode* expr1,ExprNode* expr2)
    : ExprNode(se), op(op), expr1(expr1), expr2(expr2) {
        dst = new Operand(se);
        std::string op_str;
        switch (op) {
        case OP_ADD:
            op_str = "+";
            break;
        case OP_SUB:
            op_str = "-";
            break;
        case OP_MUL:
            op_str = "*";
            break;
        case OP_DIV:
            op_str = "/";
            break;
        case OP_MOD:
            op_str = "%";
            break;
        case OP_AND:
            op_str = "&&";
            break;
        case OP_OR:
            op_str = "||";
            break;
        case OP_LESS:
            op_str = "<";
            break;
        case OP_LESSEQ:
            op_str = "<=";
            break;
        case OP_GREATER:
            op_str = ">";
            break;
        case OP_GREATEREQ:
            op_str = ">=";
            break;
        case OP_EQUAL:
            op_str = "==";
            break;
        case OP_NOTEQUAL:
            op_str = "!=";
            break;
        }
        if(expr1->getType()->isVoid() || expr2->getType()->isVoid()){
            fprintf(stderr,
                "[INFO] Invalid operand of type \'void\' to binary \'opeartor%s\'\n",
                op_str.c_str());
        }
        if(op >= OP_AND && op<= OP_GREATEREQ) {
            this->type = TypeSystem::boolType;
            if(op == OP_AND || op == OP_OR) {
                if(expr1->getType()->isNum()&&expr1->getType()->getSize()==32){
                    ImplictCastExpr* temp = new ImplictCastExpr(expr1);
                    this->expr1 = temp;
                }
                if(expr2->getType()->isNum()&&expr2->getType()->getSize()==32){
                    ImplictCastExpr* temp = new ImplictCastExpr(expr2);
                    this->expr2 = temp;
                }
            }else{
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat()){
                    if(expr1->getType()->isInt()){
                        ImplictCastFloatExpr* temp1 = new ImplictCastFloatExpr(expr1);
                        this->expr1 = temp1;
                    }
                    if(expr2->getType()->isInt()){
                        ImplictCastFloatExpr* temp2 = new ImplictCastFloatExpr(expr2);
                        this->expr2 = temp2;
                    }
            }
            }
        }
        else {
            if(expr1->getType()->isFloat()||expr2->getType()->isFloat()){
                this->type = TypeSystem::floatType;
                if(expr1->getType()->isInt()){
                    ImplictCastFloatExpr* temp1 = new ImplictCastFloatExpr(expr1);
                    this->expr1 = temp1;
                }
                if(expr2->getType()->isInt()){
                    ImplictCastFloatExpr* temp2 = new ImplictCastFloatExpr(expr2);
                    this->expr2 = temp2;
                }
            }
            else
                this->type = TypeSystem::intType;
        }
        //printf("[IFNO] binaray type -> %s\n", this->type->toStr().c_str());
}

UnaryExpr::UnaryExpr(SymbolEntry* se, int op, ExprNode* expr)
    : ExprNode(se, EXPR_UNARY), op(op), expr(expr) {
        std::string op_str;
        switch (op) {
        case OP_NOT:
            op_str = "!";
            break;
        case OP_SUB:
            op_str = "-";
            break;
        }
        if(expr->getType()->isVoid()){
            fprintf(stderr,
                "[INFO] Invalid operand of type \'void\' to unary \'opeartor%s\'\n",
                op_str.c_str());
        }
        if(op == OP_SUB) {
            type = expr->getType()->isInt() ? TypeSystem::intType : TypeSystem::floatType;
            dst = new Operand(se);
            if(expr->isUnaryExpr()) {
                UnaryExpr* ue = (UnaryExpr*)expr;
                if(ue->getOp() == OP_NOT)
                    if (ue->getType()->isNum())
                        ue->setType(TypeSystem::boolType);
            }
        }else if( op == OP_NOT) {
            type = TypeSystem::intType;
            dst = new Operand(se);
            if(expr->isUnaryExpr()) {
                UnaryExpr* ue = (UnaryExpr*)expr;
                if(ue->getOp() == OP_NOT)
                    if (ue->getType()->isNum())
                        ue->setType(TypeSystem::boolType);
            }
        }

}

//gencode
void Ast::genCode(Unit* unit) {
    IRBuilder* builder = new IRBuilder(unit);
    Node::setIRBuilder(builder);
    root->genCode();
}

void FunDefStmt::genCode()
{
    Unit *unit = builder->getUnit();  //get the current unit
    Function *func = new Function(unit, se);
    BasicBlock *entry = func->getEntry();
    // set the insert point to the entry basicblock of this function.
    builder->setInsertBB(entry);

    if(decl)
        decl->genCode();
    if(stmt)
        stmt->genCode();

    /**
     * Construct control flow graph. You need do set successors and predecessors for each basic block.
     * Todo
    */
   for(auto block = func->begin(); block != func->end(); block++){
        //get the block last instrunction
        Instruction* index = (*block)->begin();
        Instruction* last = (*block)->rbegin();
        while(index != last){
            if(index->isCond() || index->isUncond()) 
                (*block)->remove(index);
            index = index->getNext();
        }
        if(last->isCond()) {
            BasicBlock *trueBranch, *falseBranch;
            trueBranch = dynamic_cast<CondBrInstruction*>(last)->getTrueBranch();
            falseBranch = dynamic_cast<CondBrInstruction*>(last)->getFalseBranch();
            if(trueBranch->empty())
                new RetInstruction(nullptr, trueBranch);
            else if(falseBranch->empty())
                new RetInstruction(nullptr, falseBranch);
            (*block)->addSucc(trueBranch);
            (*block)->addSucc(falseBranch);
            trueBranch->addPred(*block);
            falseBranch->addPred(*block);
        }else if(last->isUncond()) {
            BasicBlock* dst = dynamic_cast<UncondBrInstruction*>(last)->getBranch();
            (*block)->addSucc(dst);
            dst->addPred(*block);
            if(dst->empty()){
                if(((FuncType*)(se->getType()))->getRetType()->isNum())
                    new RetInstruction(new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0)), dst);
                else if(((FuncType*)(se->getType()))->getRetType()->isVoid())
                    new RetInstruction(nullptr, dst);
            }
        }
        else if(!last->isRet()) {
            if(((FuncType*)(se->getType()))->getRetType()->isVoid())
                new RetInstruction(nullptr, *block);
        }
   }   
}

void BinaryExpr::genCode() {
    BasicBlock *bb = builder->getInsertBB();
    Function *func = bb->getParent();
    if(op == OP_AND) {
        BasicBlock *trueBB = new BasicBlock(func);  // if the result of lhs is true, jump to the trueBB.
        expr1->genCode();
        backPatch(expr1->trueList(), trueBB);
        builder->setInsertBB(trueBB);               // set the insert point to the trueBB so that intructions generated by expr2 will be inserted into it.
        expr2->genCode();
        true_list = expr2->trueList();
        false_list = merge(expr1->falseList(), expr2->falseList());
    } else if (op == OP_OR) {
        // Todo
        BasicBlock* trueBB = new BasicBlock(func);
        expr1->genCode();
        backPatch(expr1->falseList(), trueBB);
        builder->setInsertBB(trueBB);
        expr2->genCode();
        true_list = merge(expr1->trueList(), expr2->trueList());
        false_list = expr2->falseList();
    } else if (op >= OP_EQUAL && op <= OP_GREATEREQ) {
        expr1->genCode();
        expr2->genCode();
        Operand* src1 = expr1->getOperand();
        Operand* src2 = expr2->getOperand();

        //ZEXT
        if(src1->getType()->getSize()==1) {
            Operand* dst = new Operand(new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel()));
            new ZextInstruction(dst, src1, bb);
            src1 = dst;
        }
        if (src2->getType()->getSize() == 1) {
            Operand* dst = new Operand(new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel()));
            new ZextInstruction(dst, src2, bb);
            src2 = dst;
        }


        int opcode;
        switch (op) {
            case OP_LESS:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FL;
                else
                    opcode = CmpInstruction::L;
                break;
            case OP_LESSEQ:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FLE;
                else
                    opcode = CmpInstruction::LE;
                break;
            case OP_GREATER:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FG;
                else
                    opcode = CmpInstruction::G;
                break;
            case OP_GREATEREQ:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FGE;
                else
                    opcode = CmpInstruction::GE;
                break;
            case OP_EQUAL:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FE;
                else
                    opcode = CmpInstruction::E;
                break;
            case OP_NOTEQUAL:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = CmpInstruction::FNE;
                else
                    opcode = CmpInstruction::NE;
                break;
        }
        new CmpInstruction(opcode, dst, src1, src2, bb);
        //temp block
        BasicBlock *truebb = new BasicBlock(func);
        BasicBlock *falsebb = new BasicBlock(func);
        BasicBlock *tempbb = new BasicBlock(func);

        true_list.push_back(new CondBrInstruction(truebb, tempbb, dst, bb));
        false_list.push_back(new UncondBrInstruction(falsebb, tempbb));
    }else if(op >= OP_ADD && op <= OP_MOD) {
        expr1->genCode();
        expr2->genCode();
        Operand* src1 = expr1->getOperand();
        Operand* src2 = expr2->getOperand();
        // printf("%s\n", src1->toStr().c_str());
        // printf("%s\n", src2->toStr().c_str());
        int opcode;
        switch (op) {
            case OP_ADD:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = BinaryInstruction::FADD;
                else
                    opcode = BinaryInstruction::ADD;
                break;
            case OP_SUB:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = BinaryInstruction::FSUB;
                else
                    opcode = BinaryInstruction::SUB;
                break;
            case OP_MUL:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = BinaryInstruction::FMUL;
                else
                    opcode = BinaryInstruction::MUL;
                break;
            case OP_DIV:
                if(expr1->getType()->isFloat()||expr2->getType()->isFloat())
                    opcode = BinaryInstruction::FDIV;
                else
                    opcode = BinaryInstruction::DIV;
                break;
            case OP_MOD:
                opcode = BinaryInstruction::MOD;
                break; 
        }
        new BinaryInstruction(opcode, dst, src1, src2, bb);
        // printf("hhhh\n");
    }
}

void ConstExpr::genCode() {
    // we don't need to generate code.
}

void IdExpr::genCode()
{
    BasicBlock *bb = builder->getInsertBB();
    Operand *addr = dynamic_cast<IdentifierSymbolEntry*>(se)->getAddr();
    if(type->isNum()){
        new LoadInstruction(dst, addr, bb);
    }
    else if(type->isArray()){
        if(arrayId){
            Type* eleType = ((ArrayType*)(this->type))->getElementType();
            Type* type = this->type;
            Operand* tempSrc = addr;
            Operand* tempDst = dst;
            ExprNode* idx = arrayId;
            bool pointer;

            while(true) {
                if(!idx) {
                    Operand* dst1 = new Operand(new TemporarySymbolEntry(new PointerType(type), SymbolTable::getLabel())); //the array address
                    Operand* idx1 = new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0)); //the fist index => 0
                    new GepInstruction(dst1, tempSrc, idx1, bb);
                    tempDst = dst1;
                    pointer = true;
                    break;
                }

                idx->genCode();
                new GepInstruction(tempDst, tempSrc, idx->getOperand(),bb);

                //until the last
                if(eleType->isNum() || eleType==TypeSystem::constFloatType || eleType==TypeSystem::constIntType)
                    break;
                eleType = ((ArrayType*)eleType)->getElementType();
                type = ((ArrayType*)type)->getElementType();
                tempSrc = tempDst;
                tempDst = new Operand(new TemporarySymbolEntry(new PointerType(type), SymbolTable::getLabel()));
                idx = (ExprNode*)(idx->getNextNode());
            }
            dst = tempDst;
            //if the right value need extra loadInstruction
            if(!pointer && !left) {
                Operand* dst1 = new Operand(new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel()));
                new LoadInstruction(dst1, dst, bb);
                dst = dst1;
            }
        }else {  //here is other, not num and array, do a gep do nothing
            Operand* idx = new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0));
            new GepInstruction(dst, addr, idx, bb);
        }
    }
}

void IfStmt::genCode()
{
    Function *func;
    BasicBlock *then_bb, *end_bb;

    func = builder->getInsertBB()->getParent();
    then_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);

    cond->genCode();
    backPatch(cond->trueList(), then_bb);
    backPatch(cond->falseList(), end_bb);

    builder->setInsertBB(then_bb);
    thenStmt->genCode();
    then_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb, then_bb);

    builder->setInsertBB(end_bb);
}

void IfElseStmt::genCode() {
    // printf("hello!\n");
    Function* func;
    BasicBlock *then_bb, *else_bb, *end_bb;
    func = builder->getInsertBB()->getParent();
    then_bb = new BasicBlock(func);
    else_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);
    cond->genCode();
    backPatch(cond->trueList(), then_bb);
    backPatch(cond->falseList(), else_bb);

    builder->setInsertBB(then_bb);
    thenStmt->genCode();
    then_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb, then_bb);

    builder->setInsertBB(else_bb);
    elseStmt->genCode();
    else_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb, else_bb);

    builder->setInsertBB(end_bb);

}

void CompoundStmt::genCode() {
    // Todo
    if (stmt)
        stmt->genCode();
}

void SeqNode::genCode() {
    // Todo
    stmt1->genCode();
    stmt2->genCode();
}

void DeclStmt::genCode()
{
    IdentifierSymbolEntry *se = dynamic_cast<IdentifierSymbolEntry *>(id->getSymbolEntry());
    if(se->isGlobal())
    {
        Operand *addr;
        SymbolEntry *addr_se;
        addr_se = new IdentifierSymbolEntry(*se);
        addr_se->setType(new PointerType(se->getType()));
        addr = new Operand(addr_se);
        se->setAddr(addr);
        unit.insertGlobal(se);
    }
    else if(se->isLocal() || se->isParam())
    {
        Function *func = builder->getInsertBB()->getParent();
        BasicBlock *entry = func->getEntry();
        Instruction *alloca;
        Operand *addr;
        SymbolEntry *addr_se;
        Type *type;
        type = new PointerType(se->getType());
        addr_se = new TemporarySymbolEntry(type, SymbolTable::getLabel());
        addr = new Operand(addr_se);
        
        alloca = new AllocaInstruction(addr, se); // allocate space for local id in function stack.
        entry->insertFront(alloca);  // allocate instructions should be inserted into the begin of the entry block.
        
        Operand* temp;
        if(se->isParam()){
            temp = se->getAddr();
        }
        se->setAddr(addr); // set the addr operand in symbol entry so that we can use it in subsequent code generation.
        if (expr) {
            BasicBlock* bb = builder->getInsertBB();
            expr->genCode();
            Operand* src = expr->getOperand();
            new StoreInstruction(addr, src, bb);
        }
        // printf("hello!%s\n", id->getSymbolEntry()->toStr().c_str());
        if(se->isParam()) {
            BasicBlock* bb = builder->getInsertBB();
            new StoreInstruction(addr, temp, bb);
        }
        // printf("hello1!%s\n", id->getSymbolEntry()->toStr().c_str());
    }
    if (this->getNextNode()) {
        this->getNextNode()->genCode();
    }
}

void ReturnStmt::genCode()
{
    // Todo
    BasicBlock* bb = builder->getInsertBB();
    Operand* src = nullptr;
    // printf("1\n");
    if(retValue) {
        retValue->genCode();
        // printf("3\n");
        src = retValue->getOperand();
    }
    new RetInstruction(src, bb);
}

void AssignStmt::genCode()
{
    BasicBlock *bb = builder->getInsertBB();
    expr->genCode();
    Operand *addr;
    Operand *src = expr->getOperand();
    if(lval->getType()->isNum()){
         addr = dynamic_cast<IdentifierSymbolEntry*>(lval->getSymbolEntry())->getAddr();
    }else if(lval->getType()->isArray()) {
        ((IdExpr*)lval)->setLeft();
        lval->genCode();
        addr = lval->getOperand();
    }
    /***
     * We haven't implemented array yet, the lval can only be ID. So we just store the result of the `expr` to the addr of the id.
     * If you want to implement array, you have to caculate the address first and then store the result into it.
     */
    
    new StoreInstruction(addr, src, bb);
}

void ExprStmt::genCode() {
    // Todo
    expr->genCode();
}

void ContinueStmt::genCode() {
    // Todo
    Function* func = builder->getInsertBB()->getParent();
    BasicBlock* bb = builder->getInsertBB();
    new UncondBrInstruction(((WhileStmt*)whileStmt)->get_cond_bb(), bb);
    BasicBlock* continue_bb = new BasicBlock(func);
    builder->setInsertBB(continue_bb);
}

void BreakStmt::genCode() {
    // Todo
    Function* func = builder->getInsertBB()->getParent();
    BasicBlock* bb =builder->getInsertBB();
    new UncondBrInstruction(((WhileStmt*)whileStmt)->get_end_bb(), bb);
    BasicBlock* break_bb = new BasicBlock(func);
    builder->setInsertBB(break_bb);
}

void WhileStmt::genCode() {
    // Todo
    Function* func;
    BasicBlock *cond_bb, *while_bb, *end_bb, *bb;
    bb = builder->getInsertBB();
    func = builder->getInsertBB()->getParent();
    cond_bb = new BasicBlock(func);
    while_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);

    this->cond_bb = cond_bb;
    this->end_bb = end_bb;

    //jump to the cond_bb
    new UncondBrInstruction(cond_bb, bb);

    builder->setInsertBB(cond_bb);
    cond->genCode();
    //backPatch
    backPatch(cond->trueList(), while_bb);
    backPatch(cond->falseList(), end_bb);

    builder->setInsertBB(while_bb);
    stmt->genCode();

    while_bb = builder->getInsertBB();
    new UncondBrInstruction(cond_bb, while_bb);

    builder->setInsertBB(end_bb);
}

void BlankStmt::genCode() {
    // Todo
}

void InitValueListExpr::genCode() {
    // Todo
}

void CallExpr::genCode() {
    // Todo
    ExprNode* temp = param;
    std::vector<Operand*> operands;
    while(temp) {
        temp->genCode();
        operands.push_back(temp->getOperand());
        temp = ((ExprNode*)temp->getNextNode());
    }
    BasicBlock* bb = builder->getInsertBB();
    new CallInstruction(dst, se, operands, bb);
}

void ExprNode::genCode() {
    // Todo
    
}

void UnaryExpr::genCode() {
    // Todo
    expr->genCode();
    if (op == OP_NOT) {
        BasicBlock* bb = builder->getInsertBB();
        Operand* src = expr->getOperand();
        if(expr->getType()->getSize() == 32) {
            Operand* t = new Operand(new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel()));
            if(expr->getType()->isInt()){
                new CmpInstruction(CmpInstruction::NE, t, src, new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0)), bb);
            }else if(expr->getType()->isFloat()){
                new CmpInstruction(CmpInstruction::FNE,t ,src, new Operand(new ConstantSymbolEntry(TypeSystem::floatType, (float)0.0)), bb);
            }
            src = t;
        }
        new XorInstruction(dst, src, bb);
    }else if (op == OP_SUB) {
        // printf("hhhh1\n");
        BasicBlock* bb = builder->getInsertBB();
        Operand* src1 = new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0));
        Operand* src2;
        if(expr->getType()->getSize() == 1) {
            src2 = new Operand(new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel()));
            // bool zext to int 
            new ZextInstruction(src2, expr->getOperand(), bb);
        }else
            src2 = expr->getOperand();
        if(expr->getType()->isFloat())
            new BinaryInstruction(BinaryInstruction::FSUB, dst, src1, src2, bb);
        else 
            new BinaryInstruction(BinaryInstruction::SUB, dst, src1, src2, bb);
    }
}

void ImplictCastExpr::genCode() {
    // Todo
    // printf("imp!\n");
    expr->genCode();
    BasicBlock  *trueBB, *tempBB, *falseBB;
    BasicBlock* bb = builder->getInsertBB();
    Function* func = bb->getParent();
    trueBB = new BasicBlock(func);
    tempBB = new BasicBlock(func);
    falseBB = new BasicBlock(func);

    if(expr->getType()->isFloat())
        new CmpInstruction(CmpInstruction::FNE, this->dst, this->expr->getOperand(), new Operand(new ConstantSymbolEntry(TypeSystem::intType, 0)), bb);
    else
        new CmpInstruction(CmpInstruction::NE, this->dst, this->expr->getOperand(), new Operand(new ConstantSymbolEntry(TypeSystem::floatType, (float)0.0)), bb);
    this->trueList().push_back(new CondBrInstruction(trueBB, tempBB, this->dst, bb));
    this->falseList().push_back(new UncondBrInstruction(falseBB, tempBB));
}

void ImplictCastFloatExpr::genCode() {
    // Todo
    // printf("imp!\n");
    expr->genCode();
    BasicBlock* bb = builder->getInsertBB();
    Operand* src = expr->getOperand();
    new SitofpInstruction(dst, src, bb);
    
}

void InitValueListExpr::fill() {
    Type* type = ((ArrayType*)(this->getType()))->getElementType();
    if (type->isArray()) {
        while (!isFull())
            this->addExpr(new InitValueListExpr(new ConstantSymbolEntry(type)));
        ExprNode* temp = expr;
        while (temp) {
            ((InitValueListExpr*)temp)->fill();
            temp = (ExprNode*)(temp->getNextNode());
        }
    }
    if (type->isInt()) {
        while (!isFull())
            this->addExpr(new ConstExpr(new ConstantSymbolEntry(type, 0)));
        return;
    }
}
