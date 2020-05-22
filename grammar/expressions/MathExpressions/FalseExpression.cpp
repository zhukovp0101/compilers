#include "FalseExpression.h"
#include "types/Boolean.h"

FalseExpression::FalseExpression() {}

std::shared_ptr<Type> FalseExpression::eval() const {
  return std::make_shared<Boolean>(false);
}

void FalseExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
