#include "ScopeLayer.h"

#include "types/Integer.h"
#include "types/UninitObject.h"

#include "../grammar/statements/VarDecl.h"
#include "types/FunctionType.h"

#include "../types/detail.h"
#include <iostream>
#include <utility>

ScopeLayer *ScopeLayer::current_ = nullptr;

ScopeLayer::ScopeLayer() {
  parent_ = current_;
  current_ = this;
};

void ScopeLayer::AddVariable(VarDecl *variable_declaration) {
  if (values_.find(variable_declaration->identifier_) != values_.end()) {
    throw std::runtime_error("Variable has declared");
  }
  values_[variable_declaration->identifier_] =
      CreateVar(variable_declaration->type_);
}

void ScopeLayer::Put(const Symbol &symbol, std::shared_ptr<Type> value) {
  ScopeLayer *current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr &&
         !current_layer->private_) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    auto value_iter = current_layer->values_.find(symbol);
    if (value_iter->second->ToString() == value->ToString()) {
      value_iter->second = std::move(value);
    } else {
      throw std::runtime_error(
          "Variable " + value_iter->first.GetName() +
          " has another type: " + value_iter->second->ToString());
    }
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

bool ScopeLayer::Has(const Symbol &symbol) {
  return values_.find(symbol) != values_.end();
}

std::shared_ptr<Type> ScopeLayer::Get(const Symbol& symbol) {
  ScopeLayer *current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr && !current_layer->private_) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    return current_layer->values_.find(symbol)->second;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

ScopeLayer::~ScopeLayer() {
  current_ = parent_;
}

//  for (auto symbol : symbols_) {
  //    for (int i = 0; i < num_tabs; ++i) {
  //      stream << "\t";
  //    }
  //    stream << symbol.GetName() << std::endl;
  //  }
  //  for (ScopeLayer* layer : children_) {
  //    layer->PrintLayer(stream, num_tabs + 1);
  //  }
//}
