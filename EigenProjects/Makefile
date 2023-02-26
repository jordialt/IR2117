all: median mode

median: median.cpp utils_eigen.o
				g++ -I/usr/include/eigen3 -o median median.cpp utils_eigen.o

mode: mode.cpp utils_eigen.o
				g++ -I/usr/include/eigen3 -o mode mode.cpp utils_eigen.o
utils_eigen.o: utils_eigen.cpp utils_eigen.hpp
				g++ -I/usr/include/eigen3 -c utils_eigen.cpp