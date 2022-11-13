# CMakeList.txt: проект CMake для ALL_TEST_PROJECT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("MOVE_SEMANTICS_TEST")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (MOVE_SEMANTICS_TEST "MOVE_SEMANTICS.cpp" "MOVE_SEMANTICS.h")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("./")
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
