#!/bin/sh
#Build with the fresh aarch64-none-linux-gnu-gcc toolchain downloaded from ARM webpage
cp  CMakeLists-downloaded-GCC.txt  CMakeLists.txt
rm  -r  build
mkdir  -p  build
cd build
cmake  ..  -DCMAKE_BUILD_TYPE=Release
make  -j
