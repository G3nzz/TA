cmake_minimum_required(VERSION 3.15..3.30)

project(cellbot
    DESCRIPTION "Interpreter in C++"
    LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

bison_target(parser src/parser.y "${GENERATED_DIR}/parser.cpp"
                    DEFINES_FILE "${GENERATED_DIR}/parser.hpp"
                    COMPILE_FLAGS -Wcounterexamples)
flex_target(scanner src/scanner.l "${GENERATED_DIR}/scanner.cpp"
                 DEFINES_FILE "${GENERATED_DIR}/scanner.hpp")
add_flex_bison_dependency(scanner parser)

set(GENERATED_OUTPUTS
    ${BISON_parser_OUTPUTS}
    ${FLEX_scanner_OUTPUTS})

add_executable(cellbot
    src/main.cpp
    src/driver.cpp
    src/ast.cpp
    src/interpreter.cpp
    src/simulation.cpp
    ${GENERATED_OUTPUTS})

target_include_directories(cellbot PRIVATE
    include
    include/cellbot
    ${GENERATED_DIR})
target_compile_options(cellbot PRIVATE
    -pedantic-errors -Wall -Wextra -Wconversion -Wsign-conversion
    -fdiagnostics-color    $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_link_options(cellbot PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_compile_features(cellbot PRIVATE cxx_std_17)
set_target_properties(cellbot PROPERTIES CXX_EXTENSIONS OFF)

