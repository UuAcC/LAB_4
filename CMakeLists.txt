cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME LAB_4)
project(${PROJECT_NAME})

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

set(LAB_TESTS "test_${PROJECT_NAME}")

include_directories(${LISTS_INCLUDE})
include_directories(${POLYNOME_INCLUDE})

add_subdirectory(${LISTS_LIB_NAME})
add_subdirectory(${POLYNOME_LIB_NAME})

set(BENCHMARK_ENABLE_TESTING OFF)
set(HAVE_STD_REGEX 0)
set(HAVE_STEADY_CLOCK 0)
set(HAVE_POSIX_REGEX 0)

add_subdirectory("googletest/" EXCLUDE_FROM_ALL)

enable_testing()

include(GoogleTest)
add_subdirectory(tests)