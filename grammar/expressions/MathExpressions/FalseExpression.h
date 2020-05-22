#pragma once
#include "grammar/expressions/Expression.h"

class FalseExpression: public Expression {
 public:
    FalseExpression();
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
};