all: median mode

median: median.cpp utils_eigen.o
				g++ -o median median.cpp utils_eigen.o

mode: mode.cpp utils_eigen.o
				g++ -o mode mode.cpp utils_eigen.o
utils_eigen.o: utils_eigen.cpp utils_eigen.hpp
				g++ -c utils_eigen.cpp