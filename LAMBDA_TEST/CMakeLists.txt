﻿# CMakeList.txt: проект CMake для ALL_TEST_PROJECT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project ("LAMBDA_TEST")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (LAMBDA_TEST "LAMBDA_TEST.cpp" "LAMBDA_TEST.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
