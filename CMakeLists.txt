cmake_minimum_required(VERSION 2.8)
project(BITSTREAM)
file(GLOB HEADER_LIST "${CMAKE_SOURCE_DIR}/include/*.hpp")
install (FILES ${HEADER_LIST} DESTINATION include)

# set include path so bitstream.cpp could find it
include_directories(${BITSTREAM_SOURCE_DIR}/include)
add_subdirectory(src)