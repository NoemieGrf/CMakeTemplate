cmake_minimum_required(VERSION 3.26)

project (SharedLibrary)

set(CMAKE_CXX_STANDARD 20)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(print SHARED ${src_files})

# add macro DLL_EXPORT to use dllexport
target_compile_definitions(print PUBLIC DLL_EXPORT)

# alias name
add_library(sub::libprint ALIAS print)

target_include_directories(print
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)