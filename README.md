# Visual Studio Code and CMake and Eclipse-CDT IDE project for SquareLine Studio and LVGL - with 64bit Raspberry Pi as compile-target


This project can be used to cross-build Raspberry Pi C/C++ UI code exported from SquareLine Studio.


## Prerequisites

General note: Please avoid folder-names and filenames containing non-ASCII (special/accented/foreign) characters for the installed tools and your exported projects. Some build-tools and terminals/OS-es don't handle those characters well or interpret them differently, which can cause issues during the build-process.


### Compiler (gcc) and generator (make):

#### For CMAke/VScode get and install the essential build-tools (binutils,compiler,linker,make,etc.) on your host-PC if you don't have them yet:

- On Windows [MinGW](https://www.mingw-w64.org/) contains them, the POSIX+SEH+UCRT-build variant at their [GitHub repository](https://github.com/niXman/mingw-builds-binaries/releases) works fine on Windows 10:
  - Download for example: [x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev0.7z](https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev0/x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev0.7z)
  - Extract/copy the compressed 7z file's included 'mingw64' folder to C:\  (Can be other folder but we continue with this here.)
  - You need to add the 'C:\mingw64\bin' folder to your PATH environment variable (Unfortunately there's no up-to-date mingw64 installer that sets it for us.)
  (On Windows 10 right-click on This PC, go to Advanced System Settings / Environment Variables, select 'Path' and add "C:\mingw64\bin" to an empty line.)
  - (You can check if the setting works by typing 'mingw32-make' on command line.)
- On Linux type in the Terminal: `sudo apt-get install gcc g++ gdb build-essential`
- On MacOS install latest Xcode

#### For Eclipse CDT you need to get and install the GNU 'Make' build-tool on your host-PC if you don't have it yet (Eclipse will use it in the background):

- On Windows [Make tool Windows support webpage](https://gnuwin32.sourceforge.net/packages/make.htm) directs to an installer:
  - Download the installer: [Make Tool Windows Installer](https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81.exe)
  - You need to add the 'C:\Program Files (x86)\GnuWin32\bin' folder to your PATH environment variable (Unfortunately there's no Make installer that sets it for us.)
  (On Windows 10 right-click on This PC, go to Advanced System Settings / Environment Variables, select 'Path' and add the folder-path mentioned above to an empty line.)
  - (You can check if the setting works by typing 'make' on command line.)
- On Linux type in the Terminal: `sudo apt-get install make`
- On MacOS install latest Xcode


### To compile for Raspberry you'll need the cross-compiler targeting 64bit ARM architecture ('aarch64')

Download one 'GNU/Linux-target' variant for your host-OS from ARM's official homepage:

- If your RPI has the new Raspberry Pi OS 12 (Bookworm having glibc-2.36) you can go on by downloading e.g. gcc-arm-12.3 (having glibc-2.34). (But the other option below, gcc-arm-10.2, works as well.)
  - Find it at webpage [Current ARM GNU Toolchain downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
  - For Windows choose the exe installer which sets PATH environment variable for you (be sure to check that option when asked!): [arm-gnu-toolchain-12.3.rel1-mingw-w64-i686-aarch64-none-linux-gnu.exe](https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-mingw-w64-i686-aarch64-none-linux-gnu.exe)
  - For Linux: [arm-gnu-toolchain-12.3.rel1-x86_64-aarch64-none-linux-gnu.tar.xz](https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-x86_64-aarch64-none-linux-gnu.tar.xz)
  (After extracting the package to your preferred place you need to add the contained 'bin' folder to your PATH in ~/.profile so you can run aarch64-none-linux-gnu-gcc and the others from any folder.)
  - For OSX it seems there's only source-code distribution

- If the RPI has the older Raspberry Pi OS 11 (Bullseye having glibc-2.31) you need to download gcc-arm-10.2 (having glibc-2.31). (Executables built with this work in the new Raspberry Pi OS 12 as well.)
  - Find it at webpage [Discontinued ARM A-profile CPU toolchain downloads](https://developer.arm.com/downloads/-/gnu-a)
  - For Windows (MinGW): [gcc-arm-10.2-2020.11-mingw-w64-i686-aarch64-none-linux-gnu.tar.xz](https://developer.arm.com/-/media/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-mingw-w64-i686-aarch64-none-linux-gnu.tar.xz)
  - For Linux: [gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu.tar.xz](https://developer.arm.com/-/media/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu.tar.xz)
  - After extracting these packages to your preferred place you need to add the contained 'bin' folder to your PATH so you can run `aarch64-none-linux-gnu-gcc` and the others from any folder.
  (Alternatively you can install by package manager on Linux, for example in LMDE 5 the 10.2 version of gcc-arm could be installed by: `sudo apt-get install gcc-aarch64-linux-gnu` but filenames lack the 'none' part and CMakeLists.txt might need to be changed.)
  (For that `aarch64-linux-gnu-gcc` there's a `CMakeLists-repository-GCC.txt` included which is used by `build-repository-GCC.sh` build-script.)

- LVGL is set to use SDL2 as a backend (beside GlibC). Original SDL2 development-library is compiled and included in this OBP file to save you from the hassles of getting and compiling it yourself
  - (The produced Raspberry Pi executable is dynamically linked, so it needs libSDL2 runtime-library to run. Raspberry Pi OS should have SDL2 runtime-library by default but you can install it by `sudo apt-get install libsdl2-2.0-0`)


### Builder:

#### For CMake/VScode building you need to get CMake tool to generate the build-chain (makefiles) for the host PC's platform:

- For Windows go to [CMake download page](https://cmake.org/download/) and select the [CMake MSI-installer binary distribution](https://github.com/Kitware/CMake/releases/download/v3.28.0-rc2/cmake-3.28.0-rc2-windows-x86_64.msi)
  (When asked by the installer, select the option that will take care of setting the PATH variable for the cmake executable.)
- For Linux you just need to get and install CMake from the repository, for example `sudo apt-get install cmake`

- If you want GUI-based build you can get and install [Visual Studio Code](https://code.visualstudio.com/download)
  - After running Visual Studio Code, you need to download 2 extensions: 'C/C++ Extension Pack' and 'CMake Tools'

#### For building with Eclipse you should have Eclipse CDT installed on your machine:
- Download it from [Eclipse Download Page](https://www.eclipse.org/downloads/)
- When asked about variants, choose Eclipse for C/C++ Developers from the list (it's usually abbreviated as CDT)
- Wait for the installation to finish, it might take a while (and seem to stall falsely complaining about slow download, but ignore it and wait patiently.)



## Usage - configuring and building the project


You have probably selected the Raspberry Pi board already and created a project with it in SquareLine Studio.
In SquareLine Studio click 'Create Template Project' and select the folder to save it to.


### If you chose CMake and command-line build is your preferred way:

#### Navigate to the exported project-folder and you'll see two batch-files (they take care of handling 'build' folder):
- On Windows you can run `build.bat` to build the project for you
- On Linux you can run `build.sh`  (You might need to set its execution-privilege by `chmod 755 build.sh` if it changed in the unzipped exported project-template.)
  (If you have the aarch64 GCC installed from linux repository, `build-repository-GCC.sh` should work instead.)

#### You can also do the cmake steps manually:
- First go to the 'build' folder and to create the build/make-files type:
  - On Windows: `cmake -G "MinGW Makefiles" ..`
  - On Linux: `cmake ..` or `cmake -G "Unix Makefiles" ..`  (or if you have and want Ninja-build, `cmake -G "Ninja" ..`)
- When make-files are ready, you can finally build the project by:
  - On Windows: `mingw32-make`
  - On Linux: `make`  (or `ninja` if you selected this one in the previous step)


### If you want to build in VScode (CMake-based build):
- Just open the project in it by 'Open Folder' (in 'File' menu) and select the exported project-template's folder.
  - If asked, allow it to download and install the CMake extension.
  - To continue you might need to press OK that you trust the source (probably asked because of included SDL binaries)
- Open the `main.c` file, and if asked allow it to download and install the C/C++ extension.
- Select the build toolkit on the bottom toolbar. (For example `GCC 10.2.1 aarch64-linux-gnu-gcc` on Linux/MinGW)
  - (You can choose 'Unspecified' and let the toolchain given by CMake settings be used, that works too.)
- Configure the CMake project with the `CMake: ...` button on the bottom toolbar. (Select preferred release type)
- Build the project with the `Build` button on the bottom toolbar.


### If you want to build in Eclipse:

#### Without CMake being involved:
- Import the project: File / Import ... / General / Existing Projects into Workspace
- Select the project-template folder exported by Squareline Studio and click 'Finish'.
- Open the `main.c` file.
- Pressing the hammer (build) button will build the project with make.

#### Or if you want to build in Eclipse-IDE with makefile generated by CMake:
- While Eclipse project settings aren't exported into the template, CMake has the ability to create Eclipse project-files (tested on Linux):
  - In the project-folder (not in the 'build' folder) type `cmake -G "Eclipse CDT4 - Unix Makefiles" .`
  - The created .settings folder and .cproject and .project files will allow the opening of the project-folder from Eclipse
    - (We don't distribute the Eclipse project files by default because they contain absolute paths which are better generated on-the-fly.)
  - In Eclipse go to File / Import / Existing Projects into Workspace, select project-folder ('root directory') and click finish
  - Pressing the hammer (build) button will build the project with make (on windows you might need to rename mingw32-make to make or create a link to it called 'make')


### To test/run:
- You can copy the generated executable file to the Raspberry by pendrive but setting up an SSH is better:
  - Transfer the generated executable file to your Raspberry PI, e.g.: scp <executable> raspberrypi:~
- Run the executable on the Raspberry PI ( from terminal / midnight-commander / file-browser or 'run' dialog )
  - (You may also test the built binary beforehand with a QEMU emulated Raspberry Pi on the host machine.)

