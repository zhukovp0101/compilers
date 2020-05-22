#include "Program.h"

Program::Program(
    List<ClassDecl>* class_decl_list
): class_decl_list_(class_decl_list) {}
void Program::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
