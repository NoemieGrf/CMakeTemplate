# cmake version required
cmake_minimum_required(VERSION 3.26)

# set the project name
project (TemplateSingleExe)

set(SOURCES
    src/math.cpp
    src/main.cpp
)

add_executable(TemplateSingleExe ${SOURCES})

target_include_directories(TemplateSingleExe
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)