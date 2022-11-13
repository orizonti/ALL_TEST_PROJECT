# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project ("ALL_TEST_PROJECT")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Включите подпроекты.
add_subdirectory ("ALL_TEST_PROJECT")
add_subdirectory ("STD_CHRONO_TEST")
add_subdirectory ("STD_THREAD_TEST")
add_subdirectory ("MOVE_SEMANTICS_TEST")
add_subdirectory ("LAMBDA_TEST")
