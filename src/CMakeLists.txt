ADD_LIBRARY(${BITSTREAM_LIBRARIES} basestream.cpp bitstream.cpp netstream.cpp)
TARGET_LINK_LIBRARIES(${BITSTREAM_LIBRARIES} ${SERVER_LIBRARIES})