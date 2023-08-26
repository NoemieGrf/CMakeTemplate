cmake_minimum_required(VERSION 3.26)

project (SharedLibrary)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(print SHARED ${src_files})

# alias name
add_library(sub::libprint ALIAS print)

target_include_directories(print
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)