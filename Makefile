all: arith_mean median mode

arith_mean:arith_mean.cc utils.o
					 g++ -o arith_mean arith_mean.cc utils.o
median:median.cc utils.o
					 g++ -o median median.cc utils.o

mode:mode.cc utils.o
					 g++ -o mode mode.cc utils.o

utils.o: utils.cc utils.hpp
					 g++ -c utils.cc