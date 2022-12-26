#ifndef __TYPE_H__
#define __TYPE_H__
#include <string>
#include <vector>
#include "define.h"
#include "SymbolTable.h"

class Type {
    private:
        int kind;

    protected:
        int size;

    public:
        Type(int kind, int size = 0) : kind(kind), size(size){};
        virtual ~Type(){};
        virtual std::string toStr() = 0;
        bool isInt() const { return kind == TYPE_INT; };
        bool isFloat() const { return kind == TYPE_FLOAT; };
        bool isNum() const { return kind == TYPE_INT || kind == TYPE_FLOAT; };
        bool isFunc() const { return kind == TYPE_FUNC; };
        bool isArray() const { return kind == TYPE_ARRAY; };
        bool isVoid() const { return kind == TYPE_VOID; };
        bool isString() const { return kind == TYPE_STRING; };
        bool isPtr() const { return kind == TYPE_PTR; };
        int getKind() const { return kind; };
        int getSize() const { return size; };

};

class IntType : public Type {
    private:
        bool constant;
    public:
        IntType(int size, bool constant = false) : Type(TYPE_INT, size), constant(constant){};
        std::string toStr();
        bool isConst() const { return constant; };
};

class FloatType : public Type {
    private:
        bool constant;
    public:
        FloatType(int size, bool constant = false) : Type(TYPE_FLOAT, size), constant(constant){};
        std::string toStr();
        bool isConst() const { return constant; };
};

class VoidType : public Type {
    public:
        VoidType() : Type(TYPE_VOID) {};
        std::string toStr();
};

class FuncType : public Type {
    private:
        Type* returnType;
        std::vector<Type*> paramsType;
        std::vector<SymbolEntry*> paramsSe;
    
    public:
        FuncType(Type* returnType, std::vector<Type*> paramsType, std::vector<SymbolEntry*> paramsSe)
            : Type(TYPE_FUNC), returnType(returnType), paramsType(paramsType), paramsSe(paramsSe) {};
        void setParamsType(std::vector<Type*> paramsType) { this->paramsType = paramsType; };
        Type* getRetType() { return returnType; };
        std::vector<Type*> getParamsType() { return paramsType; };
        std::vector<SymbolEntry*> getParamsSe() { return paramsSe; };
        std::string toStr(); 
};


class ArrayType : public Type {
    private:
        Type* elementType;
        Type* arrayType = nullptr;
        int length;
        bool constant;
    public:
        ArrayType (Type* elementType, int length, bool constant = false)
            : Type(TYPE_ARRAY), length(length), constant(constant) { size = elementType->getSize() * length; };
        std::string toStr();
        int getLength() const { return size; };
        void setArrayType(Type* arrayType) { this->arrayType = arrayType; };
        bool isConst() const { return constant; };
        Type* getElementType() const { return elementType; };
        Type* getArrayType() const { return arrayType; };
};


class StringType : public Type {
    private:
        int length;
    
    public:
        StringType(int length) : Type(TYPE_STRING), length(length) {};
        int getLength() const { return length; };
        std::string toStr();
};

class PointerType : public Type {
    private:
        Type* valueType;
    public:
        PointerType(Type* valueType) : Type(TYPE_PTR) { this->valueType = valueType; };
        std::string toStr();
        Type* getType() const { return valueType; };
};

class TypeSystem {
    private:
        static IntType commonInt;
        static IntType commonBool;
        static FloatType commonFloat;
        static VoidType commonVoid;
        static IntType commonConstInt;
        static FloatType commonConstFloat;

    public:
        static Type* intType;
        static Type* voidType;
        static Type* floatType;
        static Type* constIntType;
        static Type* constFloatType;
        static Type* boolType;
};



#endif