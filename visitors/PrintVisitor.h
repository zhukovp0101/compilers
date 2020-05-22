#pragma once

#include "../include/visitors/Visitor.h"

#include <fstream>
#include <string>

class PrintVisitor: public Visitor {
 public:
    explicit PrintVisitor(const std::string& filename);
    ~PrintVisitor();
    void Visit(Expression *element) override;
    void Visit(AndExpression *element) override;
    void Visit(AddExpression *element) override;
    void Visit(DivExpression *element) override;
    void Visit(EqExpression *element) override;
    void Visit(FalseExpression *element) override;
    void Visit(LessExpression *element) override;
    void Visit(MoreExpression *element) override;
    void Visit(ModExpression *element) override;
    void Visit(MulExpression *element) override;
    void Visit(NegativeExpression *element) override;
    void Visit(NumberExpression *element) override;
    void Visit(OrExpression *element) override;
    void Visit(SubstractExpression *element) override;
    void Visit(TrueExpression *element) override;
    void Visit(Array *element) override;
    void Visit(ArrayLength *element) override;
    void Visit(ExpressionArrayItem *element) override;
    void Visit(IdentExpression *element) override;
    void Visit(ThisExpression *element) override;
//    void Visit(VarExpression *element) override;
    void Visit(Variable *element) override;
//    void Visit(Lvalue *element) override;
    void Visit(IdentLvalue *element) override;
    void Visit(LvalueArrayItem *element) override;
    void Visit(ClassDecl *element) override;
    void Visit(ExtensionList *element) override;
    void Visit(MethodInvocation *element) override;
    void Visit(MethodDecl *element) override;
    void Visit(Assert *element) override;
    void Visit(Assignment *element) override;
//    void Visit(Declaration *element) override;
    void Visit(IfElseStatement *element) override;
    void Visit(PrintStatement *element) override;
    void Visit(ReturnStatement *element) override;
    void Visit(ScopeDecl *element) override;
//    void Visit(Statement *element) override;
    void Visit(VarDecl *element) override;
    void Visit(WhileStatement *element) override;
    void Visit(Program *element) override;
    void Visit(Lvalue *element) override;
    void Visit(Declaration *element) override;
    void Visit(Statement *element) override;

  private:
    void PrintTabs();
//    void PrintBinaryExpr(Expression* expression);
    std::ofstream stream_;
    int num_tabs_ = 0;
};
