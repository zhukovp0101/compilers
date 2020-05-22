#include "Interpreter.h"
#include "cassert"
#include "elements.h"
#include <iostream>
#include "symbol_table/ScopeLayer.h"

void Interpreter::Visit(ClassDecl *element) {
  element->declaration_list_->Accept(this);
}

void Interpreter::Visit(ExtensionList *element) {
}

void Interpreter::Visit(MethodInvocation *element) {
}

void Interpreter::Visit(MethodDecl *element) {
  if (element->identifier_ == "main") {
    ScopeLayer guard;
    element->statements_->Accept(this);
  }
}

void Interpreter::Visit(Assert *element) {
  assert((int)*std::dynamic_pointer_cast<Boolean>(element->expression_->eval()));
}
void Interpreter::Visit(Assignment *element) {
  element->variable_->Set(element->expression_->eval());
}
void Interpreter::Visit(IfElseStatement *element) {
  if ((int)*std::dynamic_pointer_cast<Boolean>(element->expression_->eval())){
    ScopeLayer guard;
    element->if_statement_->Accept(this);
  } else {
    ScopeLayer guard;
    element->else_statement_->Accept(this);
  }
}
void Interpreter::Visit(PrintStatement *element) {
  auto value = element->expression_->eval();
  if (value->ToString() == "int") {
    std::cout << (int)*std::dynamic_pointer_cast<Integer>(value) << std::endl;
    return;
  }
  if (value->ToString() == "bool") {
    std::cout << (int)*std::dynamic_pointer_cast<Boolean>(value) << std::endl;
    return;
  }
  throw std::runtime_error(value->ToString() + "cannot be printed");
}
void Interpreter::Visit(ReturnStatement *element) {
  value_ = element->expression_->eval();
}
void Interpreter::Visit(ScopeDecl *element) {
  ScopeLayer guard;
  element->statement_list_->Accept(this);
}

void Interpreter::Visit(VarDecl *element) {
  ScopeLayer::current_->AddVariable(element);
}
void Interpreter::Visit(WhileStatement *element) {
  while ((int)*std::dynamic_pointer_cast<Boolean>(element->expression_->eval())) {
    ScopeLayer guard;
    element->statement_->Accept(this);
  }
}
void Interpreter::Visit(Program *element) {
  element->class_decl_list_->Accept(this);
}

void Interpreter::Visit(Expression *element) {
  value_ = element->eval();
}
void Interpreter::Visit(Lvalue *element) {
//  element->Set(value_);
}
