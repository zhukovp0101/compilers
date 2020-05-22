#include "Visitor.h"

#include "grammar/expressions/MathExpressions/AddExpression.h"
#include "grammar/expressions/MathExpressions/AndExpression.h"
#include "grammar/expressions/MathExpressions/DivExpression.h"
#include "grammar/expressions/MathExpressions/EqExpression.h"
#include "grammar/expressions/MathExpressions/FalseExpression.h"
#include "grammar/expressions/MathExpressions/LessExpression.h"
#include "grammar/expressions/MathExpressions/ModExpression.h"
#include "grammar/expressions/MathExpressions/MoreExpression.h"
#include "grammar/expressions/MathExpressions/MulExpression.h"
#include "grammar/expressions/MathExpressions/NegativeExpression.h"
#include "grammar/expressions/MathExpressions/NumberExpression.h"
#include "grammar/expressions/MathExpressions/OrExpression.h"
#include "grammar/expressions/MathExpressions/SubstractExpression.h"
#include "grammar/expressions/MathExpressions/TrueExpression.h"
#include "grammar/expressions/Array.h"
#include "grammar/expressions/ArrayLength.h"
#include "grammar/expressions/Expression.h"
#include "grammar/expressions/ExpressionArrayItem.h"
#include "grammar/expressions/IdentExpression.h"
#include "grammar/expressions/ThisExpression.h"
#include "grammar/expressions/VarExpression.h"
#include "grammar/expressions/Variable.h"
#include "grammar/statements/ScopeDecl.h"
#include "grammar/statements/Assignment.h"
#include "grammar/lvalue/IdentLvalue.h"
#include "grammar/statements/classes/ClassDecl.h"
#include "grammar/statements/PrintStatement.h"
#include "grammar/statements/VarDecl.h"
#include "grammar/lvalue/LvalueArrayItem.h"
#include "grammar/statements/Statement.h"
//#include "grammar/statements/List.h"
#include "grammar/statements/Declaration.h"
#include "grammar/statements/ReturnStatement.h"
#include "grammar/statements/methods/MethodInvocation.h"
#include "grammar/statements/Assert.h"
#include "grammar/statements/methods/MethodDecl.h"
#include "grammar/statements/classes/ExtensionList.h"
#include "grammar/statements/ScopeAssignmentList.h"
#include "grammar/statements/WhileStatement.h"
#include "grammar/statements/IfElseStatement.h"
#include "grammar/statements/FunctionCallStatement.h"
#include "types/Type.h"
#include "Program.h"

void Visitor::Visit(AndExpression *element) {
  Visit(dynamic_cast<Expression*>(element));
}
void Visitor::Visit(AddExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(DivExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(EqExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(FalseExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(LessExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(MoreExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(ModExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(MulExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(NegativeExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(NumberExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(OrExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(SubstractExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(TrueExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(Array *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(ArrayLength *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(Expression *element) {}
void Visitor::Visit(ExpressionArrayItem *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(IdentExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(ThisExpression *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(Variable *element) {
  Visit(dynamic_cast<Expression *>(element));
}
void Visitor::Visit(Lvalue *element) {}
void Visitor::Visit(IdentLvalue *element) {
  Visit(dynamic_cast<Lvalue *>(element));
}
void Visitor::Visit(LvalueArrayItem *element) {
  Visit(dynamic_cast<Lvalue *>(element));
}
void Visitor::Visit(ClassDecl *element) {}
void Visitor::Visit(ExtensionList *element) {}
void Visitor::Visit(MethodInvocation *element) {}
void Visitor::Visit(MethodDecl *element) {}
void Visitor::Visit(Assert *element) {}
void Visitor::Visit(Assignment *element) {}
void Visitor::Visit(Declaration *element) {}
void Visitor::Visit(IfElseStatement *element) {}
void Visitor::Visit(PrintStatement *element) {}
void Visitor::Visit(ReturnStatement *element) {}
void Visitor::Visit(ScopeDecl *declaration) {
}
void Visitor::Visit(Statement *statement) {}
void Visitor::Visit(VarDecl *declaration) {}
void Visitor::Visit(WhileStatement *statement) {

}
void Visitor::Visit(Program *program) {
  program->class_decl_list_->Accept(this);
}
