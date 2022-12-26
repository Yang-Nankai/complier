%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    #include <cstring>
    #include <stack>
    extern Ast ast;

    int yylex();
    int yyerror(char const*);
    ArrayType* arrayType;
    int idx;
    int* intArrayValue;
    float* floatArrayValue;
    std::stack<InitValueListExpr*> initStack;
    InitValueListExpr* top;
    int leftCnt = 0;
    std::string tempType;
}

%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

%union {
    int itype;
    float ftype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    SymbolEntry* se;
}

%start Program
%token <strtype> ID STRING
%token <itype> INTEGER
%token <ftype> FLOATNUM
%token CONST
%token IF ELSE WHILE CONTINUE BREAK
%token INT VOID FLOAT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON LBRACKET RBRACKET COMMA
%token ADD SUB MUL DIV MOD OR AND LESS LESSEQ GREATER GREATEREQ ASSIGN EQUAL NOTEQUAL NOT
%token RETURN

%type<stmttype> Stmts Stmt AssignStmt ExprStmt BlockStmt IfStmt BlankStmt WhileStmt BreakStmt ContinueStmt ReturnStmt DeclStmt ConstDeclStmt VarDeclStmt
%type<stmttype> VarDef ConstDef FuncDef VarDefList ConstDefList FuncFParam FuncFParams InterFuncFParams 
%type<exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp MulExp ConstExp EqExp UnaryExp InitVal ConstInitVal InitValList ConstInitValList FuncRParams FuncArrayIndices ArrayIndices
%type<type> Type

%precedence THEN
%precedence ELSE
%%

Program
    : Stmts {
        ast.setRoot($1);
    }
    ;

Stmts
    : Stmt {$$=$1;}
    | Stmts Stmt{
        $$ = new SeqNode($1, $2);
    }
    ;

Stmt
    : AssignStmt {$$=$1;}
    
    | ExprStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    
    | BlankStmt {$$=$1;}
    | IfStmt {$$=$1;}
    
    | WhileStmt {$$=$1;}
    | BreakStmt {$$=$1;}
    | ContinueStmt {$$=$1;}
    
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    ;

LVal
    : ID {
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Identifier \"%s\" is undefined\n", (char*)$1);
        $$ = new IdExpr(se);
        delete []$1;
    }
    | ID ArrayIndices{
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Identifier \"%s\" is undefined\n", (char*)$1);
        $$ = new IdExpr(se, $2);
        delete []$1;
    }
    ;

AssignStmt
    : LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
        //printf("[INFO] AssignStmt\n");
    }
    ;

ExprStmt
    : Exp SEMICOLON {
        $$ = new ExprStmt($1);
    }
    ;

BlankStmt
    : SEMICOLON {
        $$ = new BlankStmt();
    }
    ;

BlockStmt
    : LBRACE {
        identifiers = new SymbolTable(identifiers); 
    } 
      Stmts RBRACE {
        $$ = new CompoundStmt($3);
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();  //return to the prev identifiers
        delete top;
    }
    | LBRACE RBRACE {
        $$ = new CompoundStmt();
    }
    ;

IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;

WhileStmt
    : WHILE LPAREN Cond RPAREN Stmt {
        $$ = new WhileStmt($3, $5);
    }
    ;

BreakStmt
    : BREAK SEMICOLON {
        $$ = new BreakStmt();
    }
    ;

ContinueStmt
    : CONTINUE SEMICOLON {
        $$ = new ContinueStmt();
    }
    ;

ReturnStmt
    : RETURN SEMICOLON {
        $$ = new ReturnStmt();
    }
    | RETURN Exp SEMICOLON {
        $$ = new ReturnStmt($2);
    }
    ;

Exp
    :
    AddExp {$$ = $1;}
    ;

Cond
    :
    LOrExp {$$ = $1;}
    ;

PrimaryExp
    : LPAREN Exp RPAREN {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
    }
    | STRING {
        SymbolEntry* se;
        se = globals->lookup(std::string($1));
        if(se == nullptr){
            Type* type = new StringType(strlen($1));
            se = new ConstantSymbolEntry(type, std::string($1));
            globals->install(std::string($1), se);
        }
        ExprNode* expr = new ExprNode(se);
        $$ = expr;
    }
    | INTEGER {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new ConstExpr(se);
    }
    | FLOATNUM {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::floatType, $1);
        $$ = new ConstExpr(se);
    }
    ;

UnaryExp 
    : PrimaryExp {$$ = $1;}
    | ID LPAREN FuncRParams RPAREN {
        //printf("[Unaray]\n");
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Function \"%s\" is undefined\n", (char*)$1);
        $$ = new CallExpr(se, $3);
        //printf("[INFO] callexpr\n");
    }
    | ID LPAREN RPAREN {
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Function \"%s\" is undefined\n", (char*)$1);
        $$ = new CallExpr(se);
    }
    | ADD UnaryExp {$$ = $2;}
    | SUB UnaryExp {
        SymbolEntry* se;
        if($2->getType()->isInt())
            se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        else if($2->getType()->isFloat())
            se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
        else 
            fprintf(stderr, "[ERROR] Something wrong in parser.y SUB UnaryExp!\n");
        $$ = new UnaryExpr(se, OP_SUB, $2);
    }
    | NOT UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, OP_NOT, $2);
    }
    ;

MulExp
    : UnaryExp {$$ = $1;}
    | MulExp MUL UnaryExp {
        Type* temp1 = $1->getType();
        Type* temp2 = $3->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_MUL, $1, $3);
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_MUL, $1, $3);
        }
    }
    | MulExp DIV UnaryExp {
        Type* temp1 = $1->getType();
        Type* temp2 = $3->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_DIV, $1, $3);
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_DIV, $1, $3);
        }
    }
    | MulExp MOD UnaryExp {
        Type* temp1 = $1->getType();
        Type* temp2 = $3->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            fprintf(stderr, "[ERROR] Module operator can't be float!\n");
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_MOD, $1, $3);
        }
    }
    ;

AddExp
    : MulExp {$$ = $1;}
    | AddExp ADD MulExp {
        Type* temp1 = $1->getType();
        Type* temp2 = $3->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_ADD, $1, $3);
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_ADD, $1, $3);
        }
    }
    | AddExp SUB MulExp {
        Type* temp1 = $1->getType();
        Type* temp2 = $3->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_SUB, $1, $3);
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new BinaryExpr(se, OP_SUB, $1, $3);
        }
    }
    ;

RelExp
    : AddExp {$$ = $1;}
    | RelExp LESS AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_LESS, $1, $3);
    }
    | RelExp LESSEQ AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_LESSEQ, $1, $3);
    }
    | RelExp GREATER AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_GREATER, $1, $3);
    }
    | RelExp GREATEREQ AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_GREATEREQ, $1, $3);
    }
    ;

EqExp
    : RelExp {$$ = $1;}
    | EqExp EQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_EQUAL, $1, $3);
    }
    | EqExp NOTEQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_NOTEQUAL, $1, $3);
    }
    ;

LAndExp
    : EqExp {$$ = $1;}
    | LAndExp AND EqExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_AND, $1, $3);
    }
    ;

LOrExp
    : LAndExp {$$ = $1;}
    | LOrExp OR LAndExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, OP_OR, $1, $3);
    }
    ;

ConstExp
    : AddExp {$$ = $1;}
    ;

FuncRParams 
    : Exp {$$ = $1;}
    | FuncRParams COMMA Exp {
        $$ = $1;
        $$->setNextNode($3);
    }

Type
    : INT {
        $$ = TypeSystem::intType;
        tempType = "int";
    }
    | VOID {
        $$ = TypeSystem::voidType;
        tempType = "void";
    }
    | FLOAT {
        $$ = TypeSystem::floatType;
        tempType = "float";
    }
    ;

DeclStmt
    : VarDeclStmt {$$ = $1;}
    | ConstDeclStmt {$$ = $1;}
    ;
VarDeclStmt
    : Type VarDefList SEMICOLON {$$ = $2;}
    ;
ConstDeclStmt
    : CONST Type ConstDefList SEMICOLON {
        $$ = $3;
    }
    ;

VarDefList
    : VarDefList COMMA VarDef {
        $$ = $1;
        $1->setNextNode($3);
    } 
    | VarDef {$$ = $1;}
    ;

ConstDefList
    : ConstDefList COMMA ConstDef {
        $$ = $1;
        $1->setNextNode($3);
    }
    | ConstDef {$$ = $1;}
    ;
VarDef
    : ID {
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::floatType, $1, identifiers->getLevel());
        if(!identifiers->install($1, se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
        $$ = new DeclStmt(new IdExpr(se));
        delete []$1;
    }
    | ID ArrayIndices {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [8]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::intType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
            ((IdentifierSymbolEntry*)se)->setIntArrayValue(intArrayValue);
            if(!identifiers->install($1, se))
                fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr(se));
            delete []$1;
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::floatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
            ((IdentifierSymbolEntry*)se)->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install($1, se))
                fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr(se));
            delete []$1;
        }
    }
    | ID ASSIGN InitVal {
        //printf("[INFO] assign1\n");
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::floatType, $1, identifiers->getLevel());
        if(!identifiers->install($1, se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
        if(tempType=="int")
            ((IdentifierSymbolEntry*)se)->setIntValue($3->getIntValue());
        else if(tempType=="float"){
            ((IdentifierSymbolEntry*)se)->setFloatValue($3->getFloatValue());
        }
        $$ = new DeclStmt(new IdExpr(se), $3);
        delete []$1;
    }
    | ID ArrayIndices ASSIGN {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::intType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [8]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::floatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
        }
        idx = 0;
        std::stack<InitValueListExpr*>().swap(initStack);
        $<se>$ = se;
    }
      InitVal {
        if(tempType=="int"){
            ((IdentifierSymbolEntry*)$<se>4)->setIntArrayValue(intArrayValue);
            if(!identifiers->install($1, $<se>4))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr($<se>4), $5);
        }else if(tempType=="float"){
            ((IdentifierSymbolEntry*)$<se>4)->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install($1, $<se>4))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr($<se>4), $5);
        }
        delete []$1;
    }
    ;
ConstDef
    : ID ASSIGN ConstInitVal {
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::constIntType, $1, identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::constFloatType, $1, identifiers->getLevel());
        if(!identifiers->install($1, se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
        if(tempType=="int")
            ((IdentifierSymbolEntry*)se)->setIntValue($3->getIntValue());
        else if(tempType=="float")
            ((IdentifierSymbolEntry*)se)->setFloatValue($3->getFloatValue());
        $$ = new DeclStmt(new IdExpr(se), $3);
        delete []$1;
    }
    | ID ArrayIndices ASSIGN {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::constIntType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = $2;  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::constFloatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
        }
        idx = 0;
        std::stack<InitValueListExpr*>().swap(initStack);
        $<se>$ = se;
    }
      ConstInitVal {
        if(tempType=="int"){
            ((IdentifierSymbolEntry*)$<se>4)->setIntArrayValue(intArrayValue);
            if(!identifiers->install($1, $<se>4))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr($<se>4), $5);
        }else if(tempType=="float"){
            ((IdentifierSymbolEntry*)$<se>4)->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install($1, $<se>4))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)$1);
            $$ = new DeclStmt(new IdExpr($<se>4), $5);
        }
        delete []$1;
    } 
    ;
ArrayIndices
    : LBRACKET ConstExp RBRACKET {
        $$ = $2;
    }
    | ArrayIndices LBRACKET ConstExp RBRACKET {
        $$ = $1;
        $1->setNextNode($3);
    }

InitVal 
    : Exp {
        /*
        int a = 1.1；不报错，但是这里设置为报错因为是高精度转低精度
        float b = 1； 不报错
        int c[3] = {1.1,1.2,1.3}; 报错
        float d[3] = {1,2,3}; 不报错
        */
        //printf("[InitVal]\n");
        if(tempType=="int"){
            //printf("[INFO] %s\n",((IdExpr*)$1)->getType()->toStr().c_str());
            //printf("[INFO] %s\n",$1->getSymbolEntry()->getType()->toStr().c_str());
            if(!$1->getType()->isInt())
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' with a value of type \'%s\'\n",$1->getType()->toStr().c_str());
        }else if(tempType=="float") {
            if(!$1->getType()->isNum()) {
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",$1->getSymbolEntry()->getType()->toStr().c_str());
            }
        }
        $$ = $1;
        //printf("[InitVal]1\n");
        if(!initStack.empty()){
            if(tempType=="int"){
                intArrayValue[idx++] = $1->getIntValue();
            }else if(tempType=="float"){
                floatArrayValue[idx++] = $1->getFloatValue();
            }
            Type* arrTy = initStack.top()->getSymbolEntry()->getType();
            if(arrTy->isNum())
                initStack.top()->addExpr($1);
            else
                while(arrTy){
                    if(((ArrayType*)arrTy)->getElementType() != TypeSystem::intType && ((ArrayType*)arrTy)->getElementType() != TypeSystem::floatType){
                        arrTy = ((ArrayType*)arrTy)->getElementType();
                        SymbolEntry* se = new ConstantSymbolEntry(arrTy);
                        InitValueListExpr* list = new InitValueListExpr(se);
                        initStack.top()->addExpr(list);
                        initStack.push(list);
                    }else{
                        initStack.top()->addExpr($1);
                        while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                            arrTy = ((ArrayType*)arrTy)->getArrayType();
                            initStack.pop();
                        }
                        break;
                    }
                }
        }
        //printf("[InitVal]2\n");         
    }
    | LBRACE RBRACE {
        SymbolEntry* se;
        ExprNode* list;
        if(tempType=="int")
        {
            if(initStack.empty()){
                // 如果只用一个{}初始化数组，那么栈一定为空
                memset(intArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::intType->getSize(); //here int.size == float.size
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::intType->getSize();
                memset(intArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }else if(tempType=="float")
        {
            if(initStack.empty()){
                // 如果只用一个{}初始化数组，那么栈一定为空
                memset(floatArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::intType->getSize(); //here int.size == float.size
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::intType->getSize();
                memset(floatArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }
        
        $$ = list;
    }
    | LBRACE {
        SymbolEntry* se;
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
        se = new ConstantSymbolEntry(arrayType);
        if(arrayType->getElementType() != TypeSystem::intType && arrayType->getElementType() != TypeSystem::floatType){
            arrayType = (ArrayType*)(arrayType->getElementType());
        }
        InitValueListExpr* expr = new InitValueListExpr(se);
        if(!initStack.empty())
            initStack.top()->addExpr(expr);
        initStack.push(expr);
        $<exprtype>$ = expr;
        leftCnt++;
    }
      InitValList RBRACE {
        leftCnt--;
        while(initStack.top() != $<exprtype>2 && initStack.size() > (long unsigned int)(leftCnt + 1))
            initStack.pop();
        if(initStack.top() == $<exprtype>2)
            initStack.pop();
        $$ = $<exprtype>2;
        if(!initStack.empty())
            while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                initStack.pop();
            }
        while(idx % (((ArrayType*)($$->getSymbolEntry()->getType()))->getSize()/ sizeof(int)) !=0 ){
            if(tempType=="int")
                intArrayValue[idx++] = 0;
            else if(tempType=="float")
                floatArrayValue[idx++] = 0;
        }
            
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
    }
    ;

ConstInitVal
    : ConstExp {
        if(tempType=="int"){
            if(!$1->getType()->isInt())
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",$1->getSymbolEntry()->getType()->toStr().c_str());
        }else if(tempType=="float") {
            if(!$1->getType()->isNum()) {
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",$1->getSymbolEntry()->getType()->toStr().c_str());
            }
        }
        $$ = $1;
        if(!initStack.empty()){
            if(tempType=="int"){
                intArrayValue[idx++] = $1->getIntValue();
            }else if(tempType=="float"){
                floatArrayValue[idx++] = $1->getFloatValue();
            }
            Type* arrTy = initStack.top()->getSymbolEntry()->getType();
            if(arrTy == TypeSystem::constIntType||arrTy == TypeSystem::constFloatType)
                initStack.top()->addExpr($1);
            else
                while(arrTy){
                    if(((ArrayType*)arrTy)->getElementType() != TypeSystem::constIntType&&((ArrayType*)arrTy)->getElementType() != TypeSystem::constFloatType){
                        arrTy = ((ArrayType*)arrTy)->getElementType();
                        SymbolEntry* se = new ConstantSymbolEntry(arrTy);
                        InitValueListExpr* list = new InitValueListExpr(se);
                        initStack.top()->addExpr(list);
                        initStack.push(list);
                    }else{
                        initStack.top()->addExpr($1);
                        while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                            arrTy = ((ArrayType*)arrTy)->getArrayType();
                            initStack.pop();
                        }
                        break;
                    }
                }
        }
    }
    | LBRACE RBRACE {
        SymbolEntry* se;
        ExprNode* list;
        if(tempType=="int"){
            if(initStack.empty()){
                memset(intArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::constIntType->getSize();
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::constIntType->getSize();
                memset(intArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }else if(tempType=="float"){
            if(initStack.empty()){
                memset(floatArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::constIntType->getSize();
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::constIntType->getSize();
                memset(floatArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }
        
        $$ = list;
    }
    | LBRACE {
        SymbolEntry* se;
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
        se = new ConstantSymbolEntry(arrayType);
        if(arrayType->getElementType() != TypeSystem::intType && arrayType->getElementType() != TypeSystem::floatType){
            arrayType = (ArrayType*)(arrayType->getElementType());
        }
        InitValueListExpr* expr = new InitValueListExpr(se);
        if(!initStack.empty())
            initStack.top()->addExpr(expr);
        initStack.push(expr);
        $<exprtype>$ = expr;
        leftCnt++;
    } 
      ConstInitValList RBRACE {
        leftCnt--;
        while(initStack.top() != $<exprtype>2 && initStack.size() > (long unsigned int)(leftCnt + 1))
            initStack.pop();
        if(initStack.top() == $<exprtype>2)
            initStack.pop();
        $$ = $<exprtype>2;
        if(!initStack.empty())
            while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                initStack.pop();
            }
        while(idx % (((ArrayType*)($$->getSymbolEntry()->getType()))->getSize()/ sizeof(int)) !=0 ){
            if(tempType=="int")
                intArrayValue[idx++] = 0;
            else if(tempType=="float")
                floatArrayValue[idx++] = 0;
        }
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
    }
    ;
InitValList
    : InitVal {
        $$ = $1;
    }
    | InitValList COMMA InitVal {
        $$ = $1;
    }
    ;
ConstInitValList
    : ConstInitVal {
        $$ = $1;
    }
    | ConstInitValList COMMA ConstInitVal {
        $$ = $1;
    }
    ;
FuncDef
    :
    Type ID {
        identifiers = new SymbolTable(identifiers);
    }
    LPAREN InterFuncFParams RPAREN {
        Type* funcType;
        std::vector<Type*> vecType;
        std::vector<SymbolEntry*> vecSe;
        DeclStmt* temp = (DeclStmt*)$5;
        while(temp){
            vecType.push_back(temp->getId()->getSymbolEntry()->getType());
            vecSe.push_back(temp->getId()->getSymbolEntry());
            temp = (DeclStmt*)(temp->getNextNode());
        }
        funcType = new FuncType($1, vecType, vecSe);
        SymbolEntry* se = new IdentifierSymbolEntry(funcType, $2, identifiers->getPrev()->getLevel());
        if(!identifiers->getPrev()->install($2, se))
            fprintf(stderr, "[ERROR] Redifinition of \'%s %s\'\n",se->getType()->toStr().c_str(), $2);
        $<se>$ = se;
        //printf("[INFO] funcdef\n");
    }
    BlockStmt {
        $$ = new FunDefStmt($<se>7, (DeclStmt*)$5, $8);
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    ;
InterFuncFParams
    : FuncFParams {$$ = $1;}
    | %empty {$$ = nullptr;}
FuncFParams
    : FuncFParams COMMA FuncFParam {
        $$ = $1;
        $$->setNextNode($3);
    }
    | FuncFParam {$$ = $1;}
    ;
FuncFParam
    : Type ID {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        //here need to set params addr for the IR
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        $$ = new DeclStmt(new IdExpr(se));
        delete []$2;
    }
    | Type ID FuncArrayIndices {
        // 这里也需要求值
        SymbolEntry* se;
        ExprNode* temp = $3;
        Type* arr = TypeSystem::intType;
        std::stack<ExprNode*> stk;
        while(temp){
            stk.push(temp);
            temp = (ExprNode*)(temp->getNextNode());
        }
        while(!stk.empty()){
            arr = new ArrayType(arr, stk.top()->getIntValue());
            stk.pop();
        }
        se = new IdentifierSymbolEntry(arr, $2, identifiers->getLevel());
        identifiers->install($2, se);
        //here need to set params addr for the IR
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        $$ = new DeclStmt(new IdExpr(se));
        delete []$2;
    }
    ;

FuncArrayIndices 
    : LBRACKET RBRACKET {
        $$ = new ExprNode(nullptr);
    }
    | FuncArrayIndices LBRACKET Exp RBRACKET {
        $$ = $1;
        $$->setNextNode($3);
    }
    ;
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
