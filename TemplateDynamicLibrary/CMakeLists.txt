cmake_minimum_required(VERSION 3.26)

project (TemplateDll)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(TemplateDll SHARED ${src_files})

target_include_directories(TemplateDll
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)