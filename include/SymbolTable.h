#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <assert.h>
#include <map>
#include <string>
#include "define.h"


class Type;
class Operand;

class SymbolEntry {
    private:
        int kind;
        SymbolEntry* nextSe;

    protected:
        Type* type;
    
    public:
        SymbolEntry(Type* type, int kind): kind(kind), type(type) {};
        virtual ~SymbolEntry(){};
        bool isConstant() const { return kind == SYM_CONSTANT; };
        bool isTemporary() const { return kind == SYM_TEMPORARY; };
        bool isVariable() const { return kind == SYM_VARIABLE; };
        Type* getType() { return type; };
        void setType(Type* type) { this->type = type; };
        virtual std::string toStr() = 0;
        bool setNextSe(SymbolEntry* se);
        SymbolEntry* getNextSe() const { return nextSe; };

};

class SymbolTable {
    private:
        std::map<std::string, SymbolEntry*> symbolTable;
        SymbolTable* prev;
        int level;
        static int counter;

    public:
        SymbolTable();
        SymbolTable(SymbolTable* prev);
        bool install(std::string name, SymbolEntry* entry);
        SymbolEntry* lookup(std::string name);
        SymbolTable* getPrev() { return prev; };
        int getLevel() { return level; };
        static int getLabel() { return counter++; };
};

class ConstantSymbolEntry : public SymbolEntry {
    private:
        int intValue;
        float floatValue;
        std::string strValue;

    public:
        ConstantSymbolEntry(Type* type, int value);
        ConstantSymbolEntry(Type* type, float value);
        ConstantSymbolEntry(Type* type, std::string strValue);
        ConstantSymbolEntry(Type* type);
        virtual ~ConstantSymbolEntry(){};
        int getIntValue() const { return intValue; };
        float getFloatValue() const { return floatValue; };
        std::string getStrValue() const { return strValue; };
        std::string toStr();
};

class IdentifierSymbolEntry : public SymbolEntry {
    private:
        enum { GLOBAL, PARAM, LOCAL };
        std::string name;
        int scope;
        int intValue;
        float floatValue;
        int label;
        bool initial;
        bool sysy;
        int* intArrayValue;
        float* floatArrayValue;
        bool allZero;
        Operand* addr; // The address of the identifier.

    public:
        IdentifierSymbolEntry(Type* type, std::string name, int scope, bool sysy=false);
        virtual ~IdentifierSymbolEntry(){};
        std::string toStr();
        bool isGlobal() const { return scope == GLOBAL; };
        bool isParam() const { return scope == PARAM; };
        bool isLocal() const { return scope >= LOCAL; };
        bool isSysy() const { return sysy; };
        int getScope() const { return scope; };
        void setIntValue(int value);
        void setFloatValue(float value);
        int getIntValue() const { return intValue;};
        float getFloatValue() const { return floatValue; };
        void setIntArrayValue(int* arrayValue);
        void setFloatArrayValue(float* arrayValue);
        int* getIntArrayValue() const { return intArrayValue; };
        float* getFloatArrayValue() const { return floatArrayValue; };
        int getLabel() const { return label; };
        void setLabel() { label = SymbolTable::getLabel(); };
        void setAllZero() { allZero = true; };
        bool isAllZero() const { return allZero; };
        Operand* getAddr() { return addr; };
        void setAddr(Operand* addr) { this->addr = addr; };

};

class TemporarySymbolEntry : public SymbolEntry {
    private:
        int label;
    public:
        TemporarySymbolEntry(Type* type, int label) : SymbolEntry(type, SYM_TEMPORARY), label(label){};
        virtual ~TemporarySymbolEntry(){};
        std::string toStr();
        int getLabel() const { return label; };
};

extern SymbolTable* identifiers;
extern SymbolTable* globals;


#endif