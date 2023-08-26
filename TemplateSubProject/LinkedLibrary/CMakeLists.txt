cmake_minimum_required(VERSION 3.26)

project(LinkedLibrary)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(util STATIC ${src_files})

# alias name
add_library(sub::libutil ALIAS util)

target_include_directories(util
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)

