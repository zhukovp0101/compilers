#pragma once

#include "Type.h"
#include <memory>
#include "Integer.h"
#include "Boolean.h"
#include "ClassType.h"
std::shared_ptr<Type> CreateVar(const std::string& type) ;

//std::shared_ptr<T> GetVar() {
//
//}

//template <class T>
//std::shared_ptr<T> GetVar(const std::shared_ptr<Type>& variable) {
//  return std::dynamic_pointer_cast<T>(variable);
//}
