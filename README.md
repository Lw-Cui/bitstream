# bitstream

Bit fstream for C++.

## Compile and link
### Standalone
```
mkdir build && cd build
cmake ..
make
```
### Submodule
When using a git submodule and CMake-buildsystem, add the following lines to your `CMakeLists.txt`:
```
ADD_SUBDIRECTORY(bitstream)
```
This will produce two important CMake variables, CPR_INCLUDE_DIRS and CPR_LIBRARIES, which you'll use in the typical way:
```
include_directories(${BITSTREAM_INCLUDE_DIRS})
target_link_libraries(your_target_name ${BITSTREAM_LIBRARIES})
```
