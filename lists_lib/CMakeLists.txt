set(target ${LISTS_LIBRARY})
file(GLOB hdrs "${LISTS_INCLUDE}/*.h*")

add_library(${target} STATIC ${hdrs} library.cpp)

if(MSVC)
    target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug>:/MDd>" "$<$<CONFIG:Release>:/MD>")
endif()

set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${target} ${LIBRARY_DEPS})