#include "SymbolTreeVisitor.h"

#include "elements.h"

#include <iostream>

#include "types/Integer.h"


//SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
//
//    tree_.root_->DeclareVariable(Symbol("one"));
//    tree_.root_->DeclareVariable(Symbol("two"));
//
////    tree_.root_->Put(Symbol("one"), std::make_shared<Integer>(1));
////    tree_.root_->Put(Symbol("two"), std::make_shared<Integer>(2));
//
//    current_layer_ = tree_.root_;
//
////    path_.push_back(tree_.root_);
//}
//
//void SymbolTreeVisitor::Visit(Declaration* declaration) {
//    std::cout << "Declaring var " << var_decl->variable_ << std::endl;
//    current_layer_->DeclareVariable(var_decl->variable_);
//}
//
//void SymbolTreeVisitor::Visit(ScopeAssignmentList* list) {
//    auto new_layer = new ScopeLayer(current_layer_);
//
//    current_layer_ = new_layer;
//    list->statement_list->Accept(this);
//    current_layer_ = current_layer_->GetParent();
//}
//
//void SymbolTreeVisitor::Visit(Program* program) {
//    program->function_->Accept(this);
//}
//
//ScopeLayerTree SymbolTreeVisitor::GetRoot() {
//    return tree_;
//}
//
//void SymbolTreeVisitor::Visit(ParamList *param_list) {
//  for (const std::string& param: param_list->params_) {
//    current_layer_->DeclareVariable(Symbol(param));
//  }
//}
//
//void SymbolTreeVisitor::Visit(Function *function) {
//  current_layer_->DeclareFunction(Symbol(function->name_), function);
//
//  auto new_layer = new ScopeLayer(current_layer_);
//
//  current_layer_ = new_layer;
//
//  function->param_list_->Accept(this);
//  function->statements_->Accept(this);
//
//  tree_.AddMapping(Symbol(function->name_), new_layer);
//
//  current_layer_ = current_layer_->GetParent();
//
//  functions_[Symbol(function->name_)] = function;
//
//}
//
//std::unordered_map<Symbol, Function *> SymbolTreeVisitor::GetFunctions() const {
//  return functions_;
//}
