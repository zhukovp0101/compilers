//
// Created by bevertax on 04.04.2020.
//

#include "ClassType.h"
ClassType::ClassType(std::string_view class_name): class_name_(class_name) {
}
std::string ClassType::ToString() {
  return class_name_;
}
