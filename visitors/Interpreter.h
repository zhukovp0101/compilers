#include "TemplateVisitor.h"

#include "symbol_table/Table.h"
#include <map>

#include "symbol_table/ScopeLayerTree.h"

#include "../include/visitors/Visitor.h"

#include <fstream>
#include <string>

class Interpreter : public Visitor {
public:
  Interpreter() = default;
  void Visit(Expression* element) override;
  void Visit(Lvalue *element) override;

  void Visit(ClassDecl *element) override;
  void Visit(ExtensionList *element) override;
  void Visit(MethodInvocation *element) override;
  void Visit(MethodDecl *element) override;
  void Visit(Assert *element) override;
  void Visit(Assignment *element) override;
  //    void Visit(Declaration *element) override;
  void Visit(IfElseStatement *element) override;
  void Visit(PrintStatement *element) override;
  void Visit(ReturnStatement *element) override;
  void Visit(ScopeDecl *element) override;
  //    void Visit(Statement *element) override;
  void Visit(VarDecl *element) override;
  void Visit(WhileStatement *element) override;
  void Visit(Program *element) override;


private:
  //    void PrintBinaryExpr(Expression* expression);
  std::shared_ptr<Type> value_ = nullptr;
};