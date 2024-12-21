cmake_minimum_required(VERSION 3.28)
project(Bignum_Arithmetic)

set(CMAKE_CXX_STANDARD 14)

# Указываем CMake искать nlohmann_json
find_package(nlohmann_json 3.2.0 REQUIRED)

# Добавляем исполняемый файл для проекта
add_executable(Bignum_Arithmetic
        src/Numbers/Fraction.cpp
        src/Numbers/include/Fraction.h
        src/Numbers/Integer.cpp
        src/Numbers/include/Integer.h
        src/main.cpp
        src/Numbers/Natural.cpp
        src/Numbers/include/Natural.h
        src/Numbers/Polynomial.cpp
        src/Numbers/include/Polynomial.h
        src/CLI/include/CLI.h
        src/cli/CLI.cpp
        src/CLI/include/CLI.h
)

# Добавляем пути к директориям с заголовочными файлами
target_include_directories(Bignum_Arithmetic PRIVATE
        ${CMAKE_SOURCE_DIR}/src/Numbers/include
        ${CMAKE_SOURCE_DIR}/src/CLI/include
)

# Связываем библиотеку nlohmann_json с проектом
target_link_libraries(Bignum_Arithmetic PRIVATE nlohmann_json::nlohmann_json)
