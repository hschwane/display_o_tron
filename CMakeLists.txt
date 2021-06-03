# -------------------------------------------------------------
# general setup
# -------------------------------------------------------------
cmake_minimum_required(VERSION 3.8...3.19)

if(${CMAKE_VERSION} VERSION_LESS 3.19)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# -------------------------------------------------------------
# dependencies
# -------------------------------------------------------------
enable_language(C)
enable_language(CXX)
find_package(mpUtils REQUIRED)

# -------------------------------------------------------------
# set up project
# -------------------------------------------------------------

# Appends the cmake/ path to MAKE_MODULE_PATH variable.
set(CMAKE_MODULE_PATH ${mpUtils_CMAKE_SCRIPTS_PATH} ${CMAKE_MODULE_PATH})

include(GetVersionFromGit)
project(display_o_tron VERSION "${VERSION_SHORT}" LANGUAGES C CXX)

# default build configuration
include(setDefaultTypeRelease)

# -------------------------------------------------------------
# create target
# -------------------------------------------------------------
add_executable(display_o_tron
        src/main.cpp
        src/NextionHMI.cpp
        src/Dot.cpp)

# -------------------------------------------------------------
# set target properties
# -------------------------------------------------------------
set_target_properties(display_o_tron PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES)

target_compile_definitions(display_o_tron PRIVATE PROJECT_SHADER_PATH="${CMAKE_CURRENT_LIST_DIR}/shader/")
target_compile_definitions(display_o_tron PRIVATE PROJECT_RESOURCE_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/")
target_compile_definitions(display_o_tron PRIVATE "DOT_VERSION=\"${VERSION_SHORT}\"")
target_compile_definitions(display_o_tron PRIVATE "DOT_VERSION_SHA=\"${VERSION_SHA1}\"")
target_compile_definitions(display_o_tron PRIVATE "DOT_BUILD_TYPE=\"${CMAKE_BUILD_TYPE}\"")

# -------------------------------------------------------------
# link dependencies (this will also link the dependencies of dependencies and set required compiler flags)
# -------------------------------------------------------------
target_link_libraries(display_o_tron mpUtils::mpUtils)