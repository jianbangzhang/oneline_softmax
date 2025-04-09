#/usr/bin/bash



mkdir build
cd build

cmake ..
make -j4

echo "navie softmax"
./navie

echo "safe softmax"
./safe

echo "pnline softmax"
./online
