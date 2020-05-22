#pragma once

#include <statements/Declaration.h>
#include <statements/List.h>
#include <statements/Statement.h>
#include <string>
#include <string_view>
#include "../VarDecl.h"

class MethodDecl: public Declaration {
public:
  MethodDecl(std::string_view type, std::string_view identifier,
             List<VarDecl>* parameters, List<Statement>* statements);
  void Accept(Visitor *visitor) override;
  std::string type_;
  List<VarDecl>* parameters_;
  List<Statement>* statements_;
};