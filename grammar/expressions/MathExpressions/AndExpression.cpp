#include "AndExpression.h"

AndExpression::AndExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

std::shared_ptr<Type> AndExpression::eval() const {
    return std::make_shared<Boolean>(
      (int)*std::dynamic_pointer_cast<Boolean>(first->eval()) +
      (int)*std::dynamic_pointer_cast<Boolean>(second->eval()));
}
void AndExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
