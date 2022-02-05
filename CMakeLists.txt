# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp src/lexer/lexer.cpp src/ast/ast.cpp src/ast/ast.h)