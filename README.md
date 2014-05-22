# requirement
g++ (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
libcppunit-dev Version: 1.12.1-4
# build
g++ -Wall main.cpp test/*.cpp src/*.cpp -lcppunit -std=c++0x -o main
# run
./main
