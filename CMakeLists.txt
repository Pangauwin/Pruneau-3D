cmake_minimum_required(VERSION 3.25)

project(MyProject
    VERSION 1.0.0
    LANGUAGES C CXX
)

# C/C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Automatically find source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
)

# Create executable
add_executable(MyProject ${PROJECT_SOURCES})

# Include directories
target_include_directories(MyProject
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
)

# Compiler warnings
if(MSVC)
    target_compile_options(MyProject PRIVATE /W4)
else()
    target_compile_options(MyProject PRIVATE -Wall -Wextra -Wpedantic)
endif()