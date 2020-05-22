#pragma once
\
#include <grammar/statements/classes/ClassDecl.h>
#include <statements/List.h>

class Program: public BaseElement {
 public:
  explicit Program(List<ClassDecl>* class_decl_list);
  void Accept(Visitor *visitor) override;

  List<ClassDecl>*class_decl_list_;
};