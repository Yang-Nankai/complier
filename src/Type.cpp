#include "Type.h"
#include <assert.h>
#include <sstream>

IntType TypeSystem::commonConstInt = IntType(32, true);
IntType TypeSystem::commonInt = IntType(32);
IntType TypeSystem::commonBool =IntType(1);
FloatType TypeSystem::commonConstFloat = FloatType(32, true);
FloatType TypeSystem::commonFloat = FloatType(32);
VoidType TypeSystem::commonVoid = VoidType();

Type* TypeSystem::constIntType = &commonConstInt;
Type* TypeSystem::intType = &commonInt;
Type* TypeSystem::constFloatType = &commonConstFloat;
Type* TypeSystem::floatType = &commonFloat;
Type* TypeSystem::voidType = &commonVoid;
Type* TypeSystem::boolType = &commonBool;

std::string IntType::toStr() {
    std::ostringstream buffer;
    if(constant)
        buffer << "i";
    else 
        buffer << "i";
    buffer << size;
    return buffer.str();
}

std::string FloatType::toStr() {
    std::ostringstream buffer;
    if(constant)
        buffer << "float";
    else
        buffer << "float";
    return buffer.str();
}

std::string VoidType::toStr() {
    return "void";
}

std::string ArrayType::toStr(){
    std::vector<std::string> arrvec;
    Type* temp = this;
    int count = 0;
    bool flag = false;
    while(temp && temp->isArray()) {
        std::ostringstream buffer;
        if (((ArrayType*)temp)->getLength() == -1) {
            flag = true;
        } else {
            buffer << "[" << ((ArrayType*)temp)->getLength() << " x ";
            count++;
            arrvec.push_back(buffer.str());
        }
        temp = ((ArrayType*)temp)->getElementType();
    }
    assert(temp->isNum());
    std::ostringstream buffer;
    for (auto it = arrvec.begin(); it != arrvec.end(); it++)
        buffer << *it;
    if(temp->isInt())
        buffer << "i32";
    else if(temp->isFloat())
        buffer << "float";
    while (count--)
        buffer << ']';
    if(flag)
        buffer << '*';

    // while(temp && temp->isArray()) {
    //     std::ostringstream buffer;
    //     if(temp == this && length == 0){
    //         buffer << '[' << ']';
    //     }else{
    //         buffer << '[' << ((ArrayType*)temp)->getLength() << ']';
    //         arrvec.push_back(buffer.str());
    //         temp = ((ArrayType*)temp)->getElementType();
    //     }
    // }
    // assert(temp->isInt() || temp->isFloat());
    // std::ostringstream buffer;
    // if(constant)
    //     buffer << "const";
    // if(temp->isInt())
    //     buffer << "int";
    // else if(temp->isFloat())
    //     buffer << "float";
    // for (auto it = arrvec.begin(); it != arrvec.end(); it++)
    //     buffer << *it;
    return buffer.str();
}

std::string FuncType::toStr() {
    std::ostringstream buffer;
    buffer << returnType->toStr() << "(";
    for (auto it = paramsType.begin(); it != paramsType.end(); it++) {
        buffer << (*it)->toStr();
        if (it + 1 != paramsType.end())
            buffer << ", ";
    }
    buffer << ")";
    return buffer.str();
}

std::string StringType::toStr() {
    std::ostringstream buffer;
    buffer << "const char[" << length << "]";
    return buffer.str();
}

std::string PointerType::toStr() {
    std::ostringstream buffer;
    buffer << valueType->toStr() << "*";
    return buffer.str();
}