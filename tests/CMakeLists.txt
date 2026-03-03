set(target ${LAB_TESTS})



file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs} ${hdrs})

if(MSVC)
    target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug>:/MDd>" "$<$<CONFIG:Release>:/MD>")
endif()

#target_compile_options(${target} PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/MDd>")

target_link_libraries(${target} gtest gtest_main ${LISTS_LIBRARY} ${POLYNOME_LIBRARY} ${ANTLR_RUNTIME_LIB_PATH} ${ANTLR_LIBRARY})

gtest_discover_tests(${target})