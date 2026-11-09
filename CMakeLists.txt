cmake_minimum_required(VERSION 3.25)

project(Pruneau-3D
    VERSION 0.0.1
    LANGUAGES C CXX
)

# C/C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# SDL3 (vendored as a git submodule)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON  CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
add_subdirectory(external/SDL EXCLUDE_FROM_ALL)


# Automatically find source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
)

# Create executable
add_executable(Pruneau-3D ${PROJECT_SOURCES})

# Include directories
target_include_directories(Pruneau-3D PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
)

# Link dependencies
target_link_libraries(Pruneau-3D PRIVATE
    SDL3::SDL3
)

# Compiler warnings
if(MSVC)
    target_compile_options(Pruneau-3D PRIVATE /W4)
else()
    target_compile_options(Pruneau-3D PRIVATE -Wall -Wextra -Wpedantic)
endif()
