set(BITSTREAM_SOURCE bitstream.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(bitstream ${BITSTREAM_SOURCE})
install (TARGETS bitstream LIBRARY DESTINATION lib/bitstream ARCHIVE DESTINATION lib/bitstream)