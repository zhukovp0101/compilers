#include "Type.h"
#include <memory>
#include "Integer.h"
#include "Boolean.h"
#include "ClassType.h"
#include "detail.h"

std::shared_ptr<Type> CreateVar(const std::string &type) {
  if (type == "int") {
    return std::make_shared<Integer>(0);
  }
  if (type == "bool") {
    return std::make_shared<Boolean>(false);
  }
  return std::make_shared<ClassType>(type);
}