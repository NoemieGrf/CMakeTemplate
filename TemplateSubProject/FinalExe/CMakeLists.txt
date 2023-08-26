cmake_minimum_required(VERSION 3.26)

project(FinalExe)

file (GLOB_RECURSE src_files src/*.cpp)

add_executable(testSubProject ${src_files})

target_link_libraries(testSubProject
        sub::libutil
        sub::libprint
)