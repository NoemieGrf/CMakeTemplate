## Generator

### Build system target files.

Example cmd for generating visual stuido files. If make program not found, set CMAKE_MAKE_PROGRAM to MSBuild.exe.

```powershell
cmake -G "Visual Studio 17 2022" -S "./" -B "./build/"
```

Example cmd for generating mingw files. If make program not found, set CMAKE_MAKE_PROGRAM to mingw32-make.exe.

``` powershell
cmake -G "MinGW Makefiles" -S "./" -B "./build/"
```

Example cmd for generating ninja files. If make program not found, set CMAKE_MAKE_PROGRAM to ninja.exe.

``` powershell
cmake -G "Ninja" -S "./" -B "./build/"
```

### Compiler

Use CMAKE_CXX_COMPILER and CMAKE_C_COMPILER to define which compiler to use.

``` shell
-DCMAKE_CXX_COMPILER="\path\to\cpp\compiler.exe"
-DCMAKE_C_COMPILER="\path\to\c\compiler.exe"
```

### Other useful command parameter

``` shell
-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE
```

This command will generate compile_commands.json in build directory, which is used for clangd C++ insights.


## Useful predefined variables

- **PROJECT_SOURCE_DIR**: directory of the last call to the project() command.
- **CMAKE_CURRENT_SOURCE_DIR**: the directory of currently processing CMakeLists.txt.
- **EXECUTABLE_OUTPUT_PATH**: binary artifacts output path.
- **PROJECT_NAME**: project name defined by project().
- **CMAKE_BUILD_TYPE**: build type, debug or release or others.
- **CMAKE_MAJOR_VERSION**: cmake major version.
- **CMAKE_MINOR_VERSION**: cmake minor version.
- **CMAKE_PATCH_VERSION**: cmake patch version.

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
target_compile_definitions(target PUBLIC DLL_EXPORT)
```

"PUBLIC" is required, should not "PRIVATE".

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

```cmake
add_custom_command(TARGET targetExe POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:targetDll> ${CMAKE_CURRENT_BINARY_DIR}/)
```

Command above means, after build finish of project "targetExe", run custom command to copy output file
of project "targetDll" to directory "CMAKE_CURRENT_BINARY_DIR".
CMAKE_COMMAND is a variable which stores the cmake executable file path, 
TARGET_FILE is a expression which returns the artifacts of project "targetDll".

