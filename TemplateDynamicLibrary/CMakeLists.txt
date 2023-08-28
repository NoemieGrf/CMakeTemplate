cmake_minimum_required(VERSION 3.26)

project (TemplateDll)

file (GLOB_RECURSE src_files src/*.cpp)

add_library(TemplateDll SHARED ${src_files})

# add macro DLL_EXPORT to use dllexport
target_compile_definitions(TemplateDll PRIVATE DLL_EXPORT)

target_include_directories(TemplateDll
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)