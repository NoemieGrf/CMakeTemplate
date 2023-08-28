cmake_minimum_required(VERSION 3.26)

project(FinalExe)

file (GLOB_RECURSE src_files src/*.cpp)

add_executable(testSubProject ${src_files})

add_custom_command(TARGET testSubProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sub::libprint> ${CMAKE_CURRENT_BINARY_DIR}/)

target_link_libraries(testSubProject
        sub::libutil
        sub::libprint
)