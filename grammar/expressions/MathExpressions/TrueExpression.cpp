#include "TrueExpression.h"

TrueExpression::TrueExpression() = default;

std::shared_ptr<Type> TrueExpression::eval() const {
  return std::make_shared<Boolean>(true);
}

void TrueExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}