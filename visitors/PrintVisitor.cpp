#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

PrintVisitor::PrintVisitor(const std::string& filename) : stream_(filename) {
}
PrintVisitor::~PrintVisitor() {
  stream_.close();
}
void PrintVisitor::Visit(AndExpression *element) {
  PrintTabs();
  stream_ << "AndExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(AddExpression *element) {
  PrintTabs();
  stream_ << "AddExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(DivExpression *element) {
  PrintTabs();
  stream_ << "DivExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(EqExpression *element) {
  PrintTabs();
  stream_ << "EqExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(FalseExpression *element) {
  PrintTabs();
  stream_ << "FalseExpression is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "false" << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(LessExpression *element) {
  PrintTabs();
  stream_ << "LessExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MoreExpression *element) {
  PrintTabs();
  stream_ << "MoreExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ModExpression *element) {
  PrintTabs();
  stream_ << "ModExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MulExpression *element) {
  PrintTabs();
  stream_ << "MulExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(NegativeExpression *element) {
  PrintTabs();
  stream_ << "NegativeExpression is:" << std::endl;
  ++num_tabs_;
  element->expression->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(NumberExpression *element) {
  PrintTabs();
  stream_ << "NumberExpression is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << (int)*std::dynamic_pointer_cast<Integer>(element->eval()) << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(OrExpression *element) {
  PrintTabs();
  stream_ << "OrExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(SubstractExpression *element) {
  PrintTabs();
  stream_ << "SubExpression is:" << std::endl;
  ++num_tabs_;
  element->first->Accept(this);
  element->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(TrueExpression *element) {
  PrintTabs();
  stream_ << "TrueExpression is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "true" << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(Array *element) {
  PrintTabs();
  stream_ << "Array is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->type_ << ' ' << element->length_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayLength *element) {
  PrintTabs();
  stream_ << "ArrayLength is:" << std::endl;
  ++num_tabs_;
  element->array_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ExpressionArrayItem *element) {
  PrintTabs();
  stream_ << "ExpressionArrayItem is:" << std::endl;
  ++num_tabs_;
  element->array_->Accept(this);
  element->item_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(IdentExpression *element) {
  PrintTabs();
  stream_ << "IdentExpression is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->identifier_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(ThisExpression *element) {
  PrintTabs();
  stream_ << "ThisExpression is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "this" << std::endl;
  --num_tabs_;
}
//void PrintVisitor::Visit(VarExpression *element) {
//
//}
void PrintVisitor::Visit(Variable *element) {
  PrintTabs();
  stream_ << "Variable is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->type_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(IdentLvalue *element) {
  PrintTabs();
  stream_ << "IdentLvalue is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->identifier_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(LvalueArrayItem *element) {
  PrintTabs();
  stream_ << "LvalueArrayItem is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->identifier_ << '[' << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
  stream_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(ClassDecl *element) {
  PrintTabs();
  stream_ << "ClassDecl is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->name_ << std::endl;
  element->extension_list_->Accept(this);
  element->declaration_list_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ExtensionList *element) {
  PrintTabs();
  stream_ << "ExtensionList is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->inherited_class_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(MethodInvocation *element) {
  PrintTabs();
  stream_ << "MethodInvocation is:" << std::endl;
  ++num_tabs_;
  element->caller_->Accept(this);
  PrintTabs();
  stream_ << element->identifier_ << std::endl;
  element->arguments_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MethodDecl *element) {
  PrintTabs();
  stream_ << "MethodDecl is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->type_ << ' ' << element->identifier_ << std::endl;
  element->parameters_->Accept(this);
  element->statements_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(Assert *element) {
  PrintTabs();
  stream_ << "Assert is:" << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(Assignment *element) {
  PrintTabs();
  stream_ << "Assignment is:" << std::endl;
  ++num_tabs_;
  element->variable_->Accept(this);
  element->expression_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(IfElseStatement *element) {
  PrintTabs();
  stream_ << "IfElseStatement is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "if" << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
  PrintTabs();
  stream_ << "then" << std::endl;
  ++num_tabs_;
  element->if_statement_->Accept(this);
  --num_tabs_;
  PrintTabs();
  stream_ << "else" << std::endl;
  ++num_tabs_;
  element->else_statement_->Accept(this);
  --num_tabs_;
  --num_tabs_;
}
void PrintVisitor::Visit(PrintStatement *element) {
  PrintTabs();
  stream_ << "PrintStatement is:" << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ReturnStatement *element) {
  PrintTabs();
  stream_ << "ReturnStatement is:" << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ScopeDecl *element) {
  PrintTabs();
  stream_ << "ScopeDecl is:" << std::endl;
  ++num_tabs_;
  element->statement_list_->Accept(this);
  --num_tabs_;
}
//void PrintVisitor::Visit(Statement *element) { Visitor::Visit(element); }
void PrintVisitor::Visit(VarDecl *element) {
  PrintTabs();
  stream_ << "VarDecl is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << element->type_ << ' ' << element->identifier_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(WhileStatement *element) {
  PrintTabs();
  stream_ << "WhileStatement is:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "While" << std::endl;
  ++num_tabs_;
  element->expression_->Accept(this);
  --num_tabs_;
  PrintTabs();
  stream_ << ":" << std::endl;
  ++num_tabs_;
  element->statement_->Accept(this);
  --num_tabs_;
  --num_tabs_;
}
void PrintVisitor::Visit(Program *element) {
  PrintTabs();
  stream_ << "Program is:" << std::endl;
  ++num_tabs_;
  element->class_decl_list_->Accept(this);
  --num_tabs_;
}

//void PrintVisitor::Visit(NumberExpression* expression) {
//    PrintTabs();
//    stream_ << "NumExpression " << expression->value_ << std::endl;
//}
//
//void PrintVisitor::Visit(AddExpression* expression) {
//    PrintTabs();
//    stream_ << "AddExpression is:" << std::endl;
//
//    ++num_tabs_;
//    expression->first->Accept(this);
//    expression->second->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(SubstractExpression* expression) {
//    PrintTabs();
//
//    stream_ << "SubExpression: " << std::endl;
//    ++num_tabs_;
//    expression->first->Accept(this);
//    expression->second->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(MulExpression* expression) {
//    PrintTabs();
//
//    stream_ << "MulExpression: " << std::endl;
//    ++num_tabs_;
//    expression->first->Accept(this);
//    expression->second->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(DivExpression* expression) {
//    PrintTabs();
//    stream_ << "DivExpression: " << std::endl;
//    ++num_tabs_;
//    expression->first->Accept(this);
//    expression->second->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(IdentExpression* expression) {
//    PrintTabs();
//
//    stream_ << "IdentExpression: " << expression->ident_ << std::endl;
//}
//
//void PrintVisitor::Visit(Assignment* assignment) {
//    PrintTabs();
//    stream_ << "Assignment: " << assignment->variable_ << std::endl;
//    ++num_tabs_;
//    assignment->expression_->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(VarDecl* var_decl) {
//    PrintTabs();
//    stream_ << "VarDecl: " << var_decl->variable_ << std::endl;
//}
//
//void PrintVisitor::Visit(PrintStatement* statement) {
//    PrintTabs();
//    stream_ << "PrintStatement: " << std::endl;
//    ++num_tabs_;
//    statement->expression_->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(AssignmentList* assignment_list) {
//    PrintTabs();
//    stream_ << "AssignmentList: " << std::endl;
//
//    ++num_tabs_;
//    for (Statement* assignment : assignment_list->statements_) {
//        assignment->Accept(this);
//    }
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(ScopeAssignmentList* list) {
//    PrintTabs();
//    stream_ << "ScopeAssignmentList:" << std::endl;
//    ++num_tabs_;
//
//    list->statement_list->Accept(this);
//    --num_tabs_;
//}
//
//void PrintVisitor::Visit(Program* program) {
//    stream_ << "Program:" << std::endl;
//
//    ++num_tabs_;
//
//    program->function_->Accept(this);
//
//    --num_tabs_;
//}
//
void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
    stream_.flush();
}
void PrintVisitor::Visit(Expression *element) { }
void PrintVisitor::Visit(Lvalue *element) {  }
void PrintVisitor::Visit(Declaration *element) {  }
void PrintVisitor::Visit(Statement *element) {  }

//
//void PrintVisitor::Visit(ParamList *param_list) {
//  PrintTabs();
//  stream_ << "ParamList:" << std::endl;
//
//  ++num_tabs_;
//
//  for (const std::string& param: param_list->params_) {
//    PrintTabs();
//    stream_ << param << std::endl;
//  }
//  --num_tabs_;
//}
//
//void PrintVisitor::Visit(Function *function) {
//  PrintTabs();
//  stream_ << "Function:" << std::endl;
//
//  ++num_tabs_;
//
//  PrintTabs();
//  stream_ << "Name: " << function->name_ << std::endl;
//  function->param_list_->Accept(this);
//  function->statements_->Accept(this);
//  --num_tabs_;
//
//}
//
//PrintVisitor::~PrintVisitor() {
//    stream_.close();
//}