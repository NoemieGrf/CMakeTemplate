cmake_minimum_required(VERSION 3.26)

project(FindPackageOpenGL)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

file (GLOB_RECURSE src_files src/*.cpp)

add_executable(exampleOpenGL ${src_files})

set_target_properties(exampleOpenGL PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)

target_include_directories(exampleOpenGL PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(exampleOpenGL ${OPENGL_LIBRARIES})