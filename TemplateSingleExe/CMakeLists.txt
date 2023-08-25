# cmake version required
cmake_minimum_required(VERSION 3.26)

# set the project name
project (TemplateSingleExe)

# collect all source
# file (GLOB ..) -> generate a list of all files that match the globbing expressions.
# file (GLOB_RECURSE ..) -> like GLOB, but traverse all the subdirectories.
file (GLOB_RECURSE src_files src/*.cpp)

add_executable(TemplateSingleExe ${src_files})

# set include paths
target_include_directories(TemplateSingleExe
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)