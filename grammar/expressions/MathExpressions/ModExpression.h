#pragma once
#include "grammar/expressions/Expression.h"

class ModExpression: public Expression {
 public:
    ModExpression(Expression* e1, Expression* e2);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};