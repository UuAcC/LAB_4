set(target ${ANTLR_LIBRARY})

file(GLOB hdrs "${ANTLR_DIR}/*.h*") 
file(GLOB src "${ANTLR_DIR}/*.cpp*")

message("h: ${hdrs}")
message("cpp: ${src}")
message("dir: ${ANTLR_DIR}")

add_library(${target} STATIC ${hdrs} ${src})

set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${target} PUBLIC ${ANTLR_RUNTIME_INCLUDE})

target_link_libraries(${target} ${ANTLR_RUNTIME_LIB_PATH})
target_link_libraries(${target} ${LIBRARY_DEPS})



