#pragma once
#include "expressions/Expression.h"
#include "types/Integer.h"
#include "types/Boolean.h"

class EqExpression: public Expression {
 public:
    EqExpression(Expression* e1, Expression* e2);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};