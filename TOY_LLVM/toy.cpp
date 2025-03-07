//
// Created by Brice on 25-3-8.
//

#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>

// using namespace llvm;

enum Token_Type
{
    EOF_TOKEN = 0,
    DEF_TOKEN,
    IDENTIFIER_TOKEN,
    NUMERIC_TOKEN,
};

namespace
{
    class BaseAST
    {
    public:
        virtual ~BaseAST() {};
        virtual llvm::Value *Codegen() = 0;
    };

    class NumericAST : public BaseAST
    {
        int numeric_val;

    public:
        NumericAST(int val) : numeric_val(val) {};
        virtual llvm::Value *Codegen();
    };

    class VariableAST : public BaseAST
    {
        std::string Var_name;

    public:
        VariableAST(const std::string &name) : Var_name(name) {};
        virtual llvm::Value *Codegen();
    };

    class BinaryAST : public BaseAST
    {
        std::string Bin_Operator;
        BaseAST *LHS, RHS;

    public:
        BinaryAST(std::string op, BaseAST *lhs, BaseAST *rhs) : Bin_Operator(op), LHS(lhs), RHS(rhs) {};
        virtual llvm::Value *Codegen();
    };
}

