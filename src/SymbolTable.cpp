#include <iostream>
#include <sstream>
#include "Type.h"
#include "SymbolTable.h"

bool SymbolEntry::setNextSe(SymbolEntry* se) {
    //function overloading....
    SymbolEntry* s = this;
    unsigned int paramNum = ((FuncType*)(se->getType()))->getParamsType().size();
    if(paramNum == ((FuncType*)(s->getType()))->getParamsType().size()){
        bool flag = false;
        std::vector<Type*> seParamType = ((FuncType*)(se->getType()))->getParamsType();
        std::vector<Type*> sParamType = ((FuncType*)(s->getType()))->getParamsType();
        for(unsigned int i = 0; i < paramNum; i ++) {
            if(seParamType[i] != sParamType[i]){
                flag = true;
                break;
            }
        }
        if(!flag)
            return false;
    }
    while (s->getNextSe()){
        if (paramNum == ((FuncType*)(s->getType()))->getParamsType().size()){
            bool flag = false;
            std::vector<Type*> seParamType = ((FuncType*)(se->getType()))->getParamsType();
            std::vector<Type*> sParamType = ((FuncType*)(s->getType()))->getParamsType();
            for(unsigned int i = 0; i < paramNum; i ++) {
                if(seParamType[i] != sParamType[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                return false;
            }
        s = s->getNextSe();
    }
    if( s == this) {
        this->nextSe = se;
    }else{
        s->setNextSe(se);
    }
    return true;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type* type, int value)
    : SymbolEntry(type, SYM_CONSTANT) {
    assert(type->isInt());
    this->intValue = value;
    this->floatValue = (float)value;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type* type, float value)
    : SymbolEntry(type, SYM_CONSTANT) {
    assert(type->isNum());
    this->floatValue = (float)value;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type* type, std::string value)
    : SymbolEntry(type, SYM_CONSTANT) {
    assert(type->isString());
    this->strValue = value;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type* type)
    : SymbolEntry(type, SYM_CONSTANT) {
    assert(type->isArray());
}


std::string float2HEX(float x){
    std::string res = "0X";
	unsigned char hex[sizeof(float)];
	unsigned char* p = (unsigned char*)&x;  //把float类型的指针强制转换为unsigned char型
	for (int i = 0; i < sizeof(float); i++)
	{
		hex[i] = *p++;//把相应地址中的数据保存到unsigned char数组中     
	}
	for (int i = 0; i < sizeof(float); i++)//小端转大端输出
	{
		res+= hex[sizeof(float) - i - 1];
	}
    return res;
}
std::string ConstantSymbolEntry::toStr() {
    std::ostringstream buffer;
    if(type->isInt())
        buffer << intValue;
    else if(type->isFloat()){
        buffer<<float2HEX(floatValue);
    }        
    else if(type->isString())
        buffer << strValue;
    return buffer.str();
}

void IdentifierSymbolEntry::setIntValue(int value) {
    if(((IntType*)(this->getType()))->isConst()) {
        if(!initial) {
            this->intValue = value;
            this->floatValue = (float)value;
            initial = true;
        }else {
            fprintf(stderr, "[CONST ERROR] Const identifier cannot set new value!\n");
        }
    }else {
        this->intValue = value;
    }
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type* type,
                                             std::string name,
                                             int scope,
                                             bool sysy)
    : SymbolEntry(type, SYM_VARIABLE), name(name), sysy(sysy) {
    this->scope = scope;
    this->initial = false;
    this->label = -1;
    this->allZero = false;
}

void IdentifierSymbolEntry::setFloatValue(float value) {
    if(((FloatType*)(this->getType()))->isConst()) {
        if(!initial) {
            this->intValue = value;
            initial = true;
        }else {
            fprintf(stderr, "[CONST ERROR] Const identifier cannot set new value!\n");
        }
    }else {
        this->floatValue = value;
    }
}

void IdentifierSymbolEntry::setIntArrayValue(int* arrayValue) {
    if(((IntType*)(this->getType()))->isConst()) {
        if(!initial) {
            this->intArrayValue = arrayValue;
            initial = true;
        }else {
            fprintf(stderr, "[CONST ERROR] Const identifier cannot set new value!\n");
        }
    }else {
        this->intArrayValue = arrayValue;
    }
}

void IdentifierSymbolEntry::setFloatArrayValue(float* arrayValue) {
    if(((FloatType*)(this->getType()))->isConst()) {
        if(!initial) {
            this->floatArrayValue = arrayValue;
            initial = true;
        }else {
            fprintf(stderr, "[CONST ERROR] Const identifier cannot set new value!\n");
        }
    }else {
        this->floatArrayValue = arrayValue;
    }
}

std::string IdentifierSymbolEntry::toStr() {
    std::ostringstream buffer;
    if(label < 0)
        buffer << "@" << name;
    else 
        buffer << "%t" << label;
    return buffer.str();
}

std::string TemporarySymbolEntry::toStr() {
    std::ostringstream buffer;
    buffer << "%t" << label;
    return buffer.str();
}

SymbolTable::SymbolTable() {
    prev = nullptr;
    level = 0;
}

SymbolTable::SymbolTable(SymbolTable* prev) {
    this->prev = prev;
    this->level = prev->level + 1;
}

SymbolEntry* SymbolTable::lookup(std::string name) {
    SymbolTable* table = this;
    while(table!=nullptr){
        if(table->symbolTable.find(name) != table->symbolTable.end())
            return table->symbolTable[name];
        else
            table = table->prev;
    }
    return nullptr;
}

bool SymbolTable::install(std::string name, SymbolEntry* entry) {
    // check the redefine
    if(this->symbolTable.find(name) != this->symbolTable.end()){
        SymbolEntry *se = this->symbolTable[name];
        if(se->getType()->isFunc())
            return se->setNextSe(entry);
        return false;
    }else {
        symbolTable[name] = entry;
        return true;
    }
}

int SymbolTable::counter = 0;
static SymbolTable t;
SymbolTable* identifiers = &t;
SymbolTable* globals = &t;




