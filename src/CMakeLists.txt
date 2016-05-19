include_directories(${BITSTREAM_INCLUDE_DIRS})
add_library(${BITSTREAM_LIBRARIES} bitstream.cpp)
target_link_libraries(${BITSTREAM_LIBRARIES})