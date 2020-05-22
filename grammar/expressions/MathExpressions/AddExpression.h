#pragma once
#include "expressions/Expression.h"
#include <types/Integer.h>

class AddExpression: public Expression {
 public:
    AddExpression(Expression* e1, Expression* e2);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor *visitor) override;
    Expression* first;
    Expression* second;
};