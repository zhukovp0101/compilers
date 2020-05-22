#pragma once
#include "expressions/Expression.h"
#include "types/Boolean.h"
class TrueExpression: public Expression {
 public:
    TrueExpression();
    [[nodiscard]] std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
};