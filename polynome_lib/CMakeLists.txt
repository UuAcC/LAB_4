set(target ${POLYNOME_LIBRARY})

file(GLOB hdrs "${POLYNOME_INCLUDE}/*.h*")
file(GLOB src "${POLYNOME_SOURCE}/*.cpp*")

add_library(${target} STATIC ${hdrs} ${src})

if(MSVC)
    target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug>:/MDd>" "$<$<CONFIG:Release>:/MD>")
endif()

set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${target} PUBLIC ${ANTLR_RUNTIME_INCLUDE})
target_link_libraries(${target} ${ANTLR_RUNTIME_LIB_PATH})

target_link_libraries(${target} ${LIBRARY_DEPS})