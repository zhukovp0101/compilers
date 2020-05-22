#pragma once

#include "Statement.h"
#include "List.h"
class ScopeDecl: public Statement {
public:
  ScopeDecl(List<Statement>* statement_list);
  void Accept(Visitor *visitor) override;

  List<Statement>* statement_list_;
};

