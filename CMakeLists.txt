cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME LAB_4)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

set(LISTS_LIB_NAME lists_lib)
set(LISTS_LIBRARY "${PROJECT_NAME}_${LISTS_LIB_NAME}")
set(LISTS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/${LISTS_LIB_NAME}")

set(POLYNOME_LIB_NAME polynome_lib)
set(POLYNOME_LIBRARY "${PROJECT_NAME}_${POLYNOME_LIB_NAME}")
set(POLYNOME_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/${POLYNOME_LIB_NAME}/include")
set(POLYNOME_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/${POLYNOME_LIB_NAME}/source")

set(ANTLR_LIB_NAME antlr_things)
set(ANTLR_LIBRARY "${PROJECT_NAME}_${ANTLR_LIB_NAME}")
set(ANTLR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${ANTLR_LIB_NAME}/generated_parser")

set(ANTLR_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${ANTLR_LIB_NAME}/antlr4_lib")
set(ANTLR_RUNTIME_INCLUDE "${ANTLR_RUNTIME_DIR}/include/antlr4-runtime")
set(ANTLR_RUNTIME_LIB_PATH "${ANTLR_RUNTIME_DIR}/lib/antlr4-runtime.lib")

set(LAB_TESTS "test_${PROJECT_NAME}")

include_directories(${LISTS_INCLUDE})
include_directories(${POLYNOME_INCLUDE})
include_directories(${ANTLR_DIR})
#include_directories(${ANTLR_RUNTIME_INCLUDE})

add_subdirectory(${LISTS_LIB_NAME})
add_subdirectory(${POLYNOME_LIB_NAME})
add_subdirectory(${ANTLR_LIB_NAME})

set(BENCHMARK_ENABLE_TESTING OFF)
set(HAVE_STD_REGEX 0)
set(HAVE_STEADY_CLOCK 0)
set(HAVE_POSIX_REGEX 0)

add_subdirectory("googletest/" EXCLUDE_FROM_ALL)

enable_testing()

include(GoogleTest)
add_subdirectory(tests)