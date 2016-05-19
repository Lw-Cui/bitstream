include_directories(${BITSTREAM_INCLUDE_DIRS})
add_executable(tests test.cpp)
target_link_libraries(tests ${BITSTREAM_LIBRARIES})