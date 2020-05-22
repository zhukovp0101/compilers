#include "NumberExpression.h"
#include <types/Integer.h>

NumberExpression::NumberExpression(int value) {
    value_ = value;
}

std::shared_ptr<Type> NumberExpression::eval() const {
  return std::make_shared<Integer>(value_);
}

void NumberExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}