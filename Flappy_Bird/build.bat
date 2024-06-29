if not exist build mkdir build
cd build
cmake -G "Ninja" -S .. -B . -DCMAKE_VERBOSE_MAKEFILE=OFF 
ninja
cd ..
.\FlappyBird.exe