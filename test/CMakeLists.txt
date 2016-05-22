include_directories(${BITSTREAM_INCLUDE_DIRS})
add_executable(BITtests test.cpp)
target_link_libraries(BITtests ${BITSTREAM_LIBRARIES})
