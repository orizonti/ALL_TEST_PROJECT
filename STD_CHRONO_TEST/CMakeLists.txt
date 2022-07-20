# CMakeList.txt: проект CMake для ALL_TEST_PROJECT; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("STD_CHRONO_TEST")
# Добавьте источник в исполняемый файл этого проекта.
add_executable (STD_CHRONO_TEST "STD_CHRONO_TEST.cpp" "STD_CHRONO_TEST.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
