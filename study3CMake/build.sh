rm -rf build
mkdir build

cd build

cmake -G "MinGW Makefiles" ../src/
make

cd ..
