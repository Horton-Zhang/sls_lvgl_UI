#!/bin/sh
#Build with the aarch64-linux-gnu-gcc linux package from linux repository
cp  CMakeLists-repository-GCC.txt  CMakeLists.txt
rm  -r  build
mkdir  -p  build
cd build
cmake  ..  -DCMAKE_BUILD_TYPE=Release
make  -j

