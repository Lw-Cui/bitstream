cmake_minimum_required(VERSION 2.8)
project(BITSTREAM)
file(GLOB HEADER_LIST "${CMAKE_SOURCE_DIR}/include/*.hpp")
install (FILES ${HEADER_LIST} DESTINATION include/bitstream)
include_directories(${BITSTREAM_SOURCE_DIR}/include)
add_subdirectory(src)

set(BITSTREAM_LIBRARIES ${BITSTREAM_SOURCE_DIR}/src/libbitstream.a CACHE INTERNAL "")
set(BITSTREAM_INCLUDE_DIRS ${BITSTREAM_SOURCE_DIR}/include CACHE INTERNAL "")

