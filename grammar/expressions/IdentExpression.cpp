#include "IdentExpression.h"
#include "../symbol_table/ScopeLayer.h"

IdentExpression::IdentExpression(std::string_view identifier): identifier_(identifier) {}

std::shared_ptr<Type> IdentExpression::eval() const {
  return ScopeLayer::current_->Get(identifier_);
}
void IdentExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
