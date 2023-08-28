# cmake version required
cmake_minimum_required(VERSION 3.26)

project (TemplateDeploy)

set(CMAKE_CXX_STANDARD 20)

# exe

file (GLOB_RECURSE src_files src/*.cpp)

add_executable(target_exe ${src_files})

target_include_directories(target_exe
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

# deploy

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}/)

install (TARGETS target_exe DESTINATION ./bin)
install (DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ./include)
install (DIRECTORY ${PROJECT_SOURCE_DIR}/config/ DESTINATION ./config)
install (FILES ${PROJECT_SOURCE_DIR}/log/log.txt DESTINATION ./)