# CMakeList.txt: проект CMake для ALL_TEST_PROJECT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("STD_THREAD_TEST")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (STD_THREAD_TEST "STD_THREAD_TEST.cpp" "STD_THREAD_TEST.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
