cmake_minimum_required(VERSION 3.0)
project(Compilers)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
        COMMAND brew --prefix bison
        RESULT_VARIABLE BREW_BISON
        OUTPUT_VARIABLE BREW_BISON_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()
    
    execute_process(
        COMMAND brew --prefix flex
        RESULT_VARIABLE BREW_FLEX
        OUTPUT_VARIABLE BREW_FLEX_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)


find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compilers_SOURCE_DIR}/bin)

set(CURRENT_EXECUTABLE "${PROJECT_NAME}Executable")

set(
    SOURCES
    driver.cpp
    visitors/Interpreter.cpp
    visitors/TemplateVisitor.cpp
    visitors/PrintVisitor.cpp
    symbol_table/Symbol.cpp
    symbol_table/Table.cpp
    symbol_table/ScopeLayer.cpp
    symbol_table/ScopeLayerTree.cpp
    types/Integer.cpp
    types/Type.cpp
    types/UninitObject.cpp
    visitors/SymbolTreeVisitor.cpp
    types/PrimitiveType.cpp
    types/PrimitiveType.h
    types/FunctionType.cpp
    types/FunctionType.h
    visitors/FunctionCallVisitor.cpp visitors/FunctionCallVisitor.h function-mechanisms/Frame.cpp function-mechanisms/Frame.h function-mechanisms/FunctionTable.cpp function-mechanisms/FunctionTable.h types/Boolean.cpp types/Boolean.h include/BaseIncludes.h grammar/statements/ScopeDecl.cpp grammar/statements/ScopeDecl.h symbol_table/ClassTable.cpp symbol_table/ClassTable.h include/visitors/Visitor.cpp symbol_table/ClassInfo.cpp symbol_table/ClassInfo.h types/ClassType.cpp types/ClassType.h include/visitors/elemants.h types/Array.cpp types/Array.h symbol_table/ScopeList.h types/detail.h types/detail.cpp)

add_subdirectory(grammar)

add_executable(
    ${CURRENT_EXECUTABLE}
    main.cpp
    ${SOURCES}
)


target_include_directories(
    ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
    ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)


target_link_libraries(${CURRENT_EXECUTABLE} GrammarLib)



