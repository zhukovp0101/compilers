#pragma once

#include "forward_decl.h"

class Visitor {
 public:
    virtual ~Visitor() = default;
    virtual void Visit(Expression *element);
    virtual void Visit(AndExpression *element);
    virtual void Visit(AddExpression *element);
    virtual void Visit(DivExpression *element);
    virtual void Visit(EqExpression *element);
    virtual void Visit(FalseExpression *element);
    virtual void Visit(LessExpression *element);
    virtual void Visit(MoreExpression *element);
    virtual void Visit(ModExpression *element);
    virtual void Visit(MulExpression *element);
    virtual void Visit(NegativeExpression *element);
    virtual void Visit(NumberExpression *element);
    virtual void Visit(OrExpression *element);
    virtual void Visit(SubstractExpression *element);
    virtual void Visit(TrueExpression *element);
    virtual void Visit(Array *element);
    virtual void Visit(ArrayLength *element);
    virtual void Visit(ExpressionArrayItem *element);
    virtual void Visit(IdentExpression *element);
    virtual void Visit(ThisExpression *element);
    virtual void Visit(Variable *element);
    virtual void Visit(Lvalue *element);
    virtual void Visit(IdentLvalue *element);
    virtual void Visit(LvalueArrayItem *element);
    virtual void Visit(ClassDecl *element);
    virtual void Visit(ExtensionList *element);
    virtual void Visit(MethodInvocation *element);
    virtual void Visit(MethodDecl *element);
    virtual void Visit(Assert *element);
    virtual void Visit(Assignment *element);
    virtual void Visit(Declaration *element);
    virtual void Visit(IfElseStatement *element);
    template <class T>
    void Visit(List<T> *list);
    virtual void Visit(PrintStatement *element);
    virtual void Visit(ReturnStatement *element);
    virtual void Visit(ScopeDecl *element);
    virtual void Visit(Statement *element);
    virtual void Visit(VarDecl *element);
    virtual void Visit(WhileStatement *element);
    virtual void Visit(Program *element);
};

template <class T> void Visitor::Visit(List<T> *list) {
  for (auto &item : list->items_) {
    item->Accept(this);
  }
}

