#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <map>
#include <vector>
#include "AsmBuilder.h"
#include <sstream>
#include "Operand.h"

class BasicBlock;

class Instruction {
   public:
    Instruction(unsigned instType, BasicBlock* insert_bb = nullptr);
    virtual ~Instruction();
    BasicBlock* getParent();
    bool isUncond() const { return instType == UNCOND; };
    bool isCond() const { return instType == COND; };
    bool isRet() const {return instType == RET;};    
    void setParent(BasicBlock*);
    void setNext(Instruction*);
    void setPrev(Instruction*);
    Instruction* getNext();
    Instruction* getPrev();
    virtual void output() const = 0;
    MachineOperand* genMachineOperand(Operand*);
    MachineOperand* genMachineReg(int reg);
    MachineOperand* genMachineVReg();
    MachineOperand* genMachineImm(int val);
    MachineOperand* genMachineLabel(int block_no);
    virtual void genMachineCode(AsmBuilder*) = 0;

   protected:
    unsigned instType;
    unsigned opcode; //opcode
    Instruction* prev; //prev instruction
    Instruction* next; //next instruction
    BasicBlock* parent; //parent bb
    std::vector<Operand*> operands; //operands
    enum {
        BINARY,
        COND,
        UNCOND,
        RET,
        LOAD,
        STORE,
        CMP,
        ALLOCA,
        CALL,
        ZEXT,
        XOR,
        GEP,
        SITOFP
    };
};

// meaningless instruction, used as the head node of the instruction list.
class DummyInstruction : public Instruction {
   public:
    DummyInstruction() : Instruction(-1, nullptr){};
    void output() const {};
    void genMachineCode(AsmBuilder*){};
};

//在内存中分配空间
class AllocaInstruction : public Instruction {
   public:
    AllocaInstruction(Operand* dst,
                      SymbolEntry* se,
                      BasicBlock* insert_bb = nullptr);
    ~AllocaInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);

   private:
    SymbolEntry* se;
};
//从内存地址中加载值到中间变量中
class LoadInstruction : public Instruction {
   public:
    LoadInstruction(Operand* dst,
                    Operand* src_addr,
                    BasicBlock* insert_bb = nullptr);
    ~LoadInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};
//将值存储到内存地址中
class StoreInstruction : public Instruction {
   public:
    StoreInstruction(Operand* dst_addr,
                     Operand* src,
                     BasicBlock* insert_bb = nullptr);
    ~StoreInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};
//二元运算指令, 包含一个目的操作数和两个源操作数
class BinaryInstruction : public Instruction {
   public:
    BinaryInstruction(unsigned opcode,
                      Operand* dst,
                      Operand* src1,
                      Operand* src2,
                      BasicBlock* insert_bb = nullptr);
    ~BinaryInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
    enum { SUB, ADD, AND, OR, MUL, DIV, MOD, FADD, FSUB, FMUL, FDIV };
};
//关系运算指令
class CmpInstruction : public Instruction {
   public:
    CmpInstruction(unsigned opcode,
                   Operand* dst,
                   Operand* src1,
                   Operand* src2,
                   BasicBlock* insert_bb = nullptr);
    ~CmpInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
    enum { E, NE, L, GE, G, LE, FE, FNE, FL, FGE, FG, FLE};
};
//无条件跳转指令，直接跳转到基本块 branch
// unconditional branch
class UncondBrInstruction : public Instruction {
   public:
    UncondBrInstruction(BasicBlock*, BasicBlock* insert_bb = nullptr);
    void output() const;
    void setBranch(BasicBlock*);
    BasicBlock* getBranch();
    void genMachineCode(AsmBuilder*);

   protected:
    BasicBlock* branch;
};
////条件跳转指令，分支为真和为假时分别跳转到基本块 true_branch 和 false_branch
// conditional branch
class CondBrInstruction : public Instruction {
   public:
    CondBrInstruction(BasicBlock*,
                      BasicBlock*,
                      Operand*,
                      BasicBlock* insert_bb = nullptr);
    ~CondBrInstruction();
    void output() const;
    void setTrueBranch(BasicBlock*);
    BasicBlock* getTrueBranch();
    void setFalseBranch(BasicBlock*);
    BasicBlock* getFalseBranch();
    void genMachineCode(AsmBuilder*);

   protected:
    BasicBlock* true_branch;
    BasicBlock* false_branch;
};

//函数返回指令
class RetInstruction : public Instruction {
   public:
    RetInstruction(Operand* src, BasicBlock* insert_bb = nullptr);
    ~RetInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};
//函数调用指令
class CallInstruction : public Instruction {
   private:
    SymbolEntry* func;

   public:
    CallInstruction(Operand* dst,
                    SymbolEntry* func,
                    std::vector<Operand*> params,
                    BasicBlock* insert_bb = nullptr);
    void output() const;
    void genMachineCode(AsmBuilder*);
};
//把操作数使用0扩展为ty2类型
class ZextInstruction : public Instruction {
   public:
    ZextInstruction(Operand* dst,
                    Operand* src,
                    BasicBlock* insert_bb = nullptr);
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class XorInstruction : public Instruction {
   public:
    XorInstruction(Operand* dst, Operand* src, BasicBlock* insert_bb = nullptr);
    void output() const;
    void genMachineCode(AsmBuilder*);
};
// GetElementPtr指令,是一条指针计算语句，本身并不进行任何数据的访问或修改，只进行指针的计算
class GepInstruction : public Instruction {
   private:
    bool first;

   public:
    GepInstruction(Operand* dst,
                   Operand* arr,
                   Operand* idx,
                   BasicBlock* insert_bb = nullptr,
                   bool first = false);
    void output() const;
    void genMachineCode(AsmBuilder*);
    
};

//sitofp use to turn int into float type
class SitofpInstruction : public Instruction {
    public:
        SitofpInstruction(Operand* dst, Operand* src, BasicBlock* insert_bb = nullptr);
        void output() const;
        void genMachineCode(AsmBuilder*);
};

#endif