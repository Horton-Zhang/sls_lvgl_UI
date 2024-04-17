copy  CMakeLists-downloaded-GCC.txt  CMakeLists.txt
rd  build  /S  /Q
md  build
cd  build
cmake  -G "MinGW Makefiles"  ..  -DCMAKE_BUILD_TYPE=Release
mingw32-make  -j

