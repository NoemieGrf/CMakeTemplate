
## Useful predefined variables

- **PROJECT_SOURCE_DIR**: directory of the last call to the project() command.
- **CMAKE_CURRENT_SOURCE_DIR**: the directory of currently processing CMakeLists.txt.
- **PROJECT_NAME**: project name defined by project().
- **CMAKE_MAJOR_VERSION**: cmake major version.
- **CMAKE_MINOR_VERSION**: cmake minor version.
- **CMAKE_PATCH_VERSION**: cmake patch version.
- **CMAKE_SYSTEM_PROCESSOR**: cpu name.
- **CMAKE_C_FLAGS**: compiler options for c compiler.
- **CMAKE_CXX_FLAGS**: compiler options for c++ compiler.
- **CMAKE_C_COMPILER**: claim c compiler.
- **CMAKE_CXX_COMPILER**: claim c++ compiler.
- **CMAKE_BUILD_TYPE**: build type, debug or release or others.

## Notes

### file

- file (GLOB ...) generate a list of all files that match the globbing expressions.
- file (GLOB_RECURSE ...) like GLOB, but traverse all the subdirectories.

``` cmake
file (GLOB_RECURSE src_files src/*.cpp)
```

### Shared Library

In windows, "__declspec(dllexport)" should be used to export the symbol. If C++ has code like bellow, 
then the macro "DLL_EXPORT" should be defined in CMakeLists.txt.

```C++
#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

DLL_API void ExportFun();
```

```cmake
target_compile_definitions(target PRIVATE DLL_EXPORT)
```

### install

Deploy files to target directory. First set the base path of deploy destination.
Following command set install path to "/output/Debug/" in current CMakeLists.txt directory.

```cmake
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}/)
```

Then use install() to deploy.

```cmake
# deploy target
install (TARGETS target_exe DESTINATION ./bin)
# deploy directory
install (DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ./include)
install (DIRECTORY ${PROJECT_SOURCE_DIR}/config/ DESTINATION ./config)
# deploy files
install (FILES ${PROJECT_SOURCE_DIR}/log/log.txt DESTINATION ./)
```

### Sub Project

#### library include private and public

When a project is mean to build a static library or shared library, target include directory should be public. 
Otherwise, other subproject which uses this library can not see the include path.

#### copy shared library

After build, shared library should be copied to the same directory with executable file.


