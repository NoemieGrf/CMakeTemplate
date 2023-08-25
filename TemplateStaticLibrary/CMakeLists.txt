cmake_minimum_required(VERSION 3.26)

project (TemplateLib)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(TemplateLib STATIC ${src_files})

target_include_directories(TemplateLib
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)