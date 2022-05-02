#ifndef KALEIDOSCOPE_AST_H
#define KALEIDOSCOPE_AST_H

#include <string>
#include <memory>
#include <vector>

class ExprAST {
public:
    // trivial constructor
    virtual ~ExprAST();
};


// Base class for all expression nodes.
class NumberExprAST : public ExprAST {
    double Val;

public:
    explicit NumberExprAST(double Val) : Val(Val) {}
};

class VariableExprAST : public ExprAST {
    std::string Name;

public:
    explicit VariableExprAST(const std::string &Name) : Name(Name) {}
};

class BinaryExprAST : public ExprAST {
    char Op;
    std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS)
            : Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

class CallExprAST : public ExprAST {
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> Args;

public:
    CallExprAST(const std::string &Callee, std::vector<std::unique_ptr<ExprAST>> Args)
            : Callee(Callee), Args(std::move(Args)) {}
};


class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;
public:
    PrototypeAST(const std::string &name, std::vector<std::string> Args) :
            Name(name), Args(std::move(Args)) {};

    [[nodiscard]]
    const std::string &getName() const { return Name; }
};

class FunstionAST {
    std::unique_ptr<PrototypeAST> Proto;
    std::unique_ptr<ExprAST> Body;

public:
    FunstionAST(std::unique_ptr<PrototypeAST> Proto, std::unique_ptr<ExprAST> Body) :
            Proto(std::move(Proto)), Body(std::move(Body)) {};
};


#endif //KALEIDOSCOPE_AST_H
