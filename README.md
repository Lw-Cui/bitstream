# bitstream

Bit fstream for C++.

## Compile and link
### Standalone
```
mkdir build && cd build
cmake ..
make
make install
```
### Submodule
When using a git submodule and CMake-buildsystem, add the following lines to your `CMakeLists.txt`:
```
ADD_SUBDIRECTORY(ext/bitstream) # Change `ext/bitstream` to a directory according to your setup
INCLUDE_DIRECTORIES(${BITSTRAM_SOURCE_DIR}/include)
```
