# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/ast/ast.h src/ast/ast.cpp src/lexer/lexer.h src/lexer/lexer.cpp src/parser/parser.cpp src/parser/parser.h)
target_include_directories(kaleidoscope PRIVATE )

add_executable(kaleidoscope src/main.cpp src/ast/ast.cpp src/lexer/lexer.cpp src/parser/parser.cpp)