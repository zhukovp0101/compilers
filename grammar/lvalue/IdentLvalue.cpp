//
// Created by bevertax on 02.04.2020.
//

#include "IdentLvalue.h"
#include "../symbol_table/ScopeLayer.h"

IdentLvalue::IdentLvalue(std::string_view identifier): identifier_(identifier) {}
void IdentLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
void IdentLvalue::Set(const std::shared_ptr<Type>& value) {
  ScopeLayer::current_->Put(identifier_, value);
}
