cmake_minimum_required(VERSION 3.26)

project (TemplateWindowsSubsystem)

set(CMAKE_CXX_STANDARD 20)

file (GLOB_RECURSE src_files src/*.cpp)

add_executable(windows ${src_files})

set_target_properties(windows PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)