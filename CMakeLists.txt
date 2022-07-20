# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("ALL_TEST_PROJECT")

# Включите подпроекты.
add_subdirectory ("ALL_TEST_PROJECT")
add_subdirectory ("STD_CHRONO_TEST")
add_subdirectory ("STD_THREAD_TEST")
