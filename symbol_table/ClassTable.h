#pragma once

#include "BaseIncludes.h"
#include <grammar/statements/classes/ClassDecl.h>
#include "ClassInfo.h"

using ClassTable = std::unordered_map<std::string, ClassInfo>; // ClassName : ClassInfo

static ClassTable class_table;