# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MatrixProject)

# Установим стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Добавляем директории заголовочных файлов
include_directories(header)

# Добавляем исходные файлы
add_executable(my_program
    source/Supporting/Vector_operations.cpp
    source/Matrix/Constructor.cpp
    source/Matrix/Matrix.cpp
    main.cpp
)