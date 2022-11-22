# CMakeList.txt: проект CMake для ALL_TEST_PROJECT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project ("OPERATION_PRECEDENCE")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (OPERATION_PRECEDENCE "OPERATION_PRECEDENCE.cpp" "OPERATION_PRECEDENCE.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
