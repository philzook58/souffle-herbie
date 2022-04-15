libgmpstubs.so: gmpstubs.cpp
	g++ -c -fPIC -o gmpstubs.o -std=c++17 gmpstubs.cpp -I/usr/include/lua5.3 -I/home/philip/Documents/prolog/souffle/src/include -fopenmp
	g++ -shared -o libgmpstubs.so gmpstubs.o -lgmp -lgmpxx -fopenmp

all: libgmpstubs.so

clean:
	rm libgmpstubs.so gmpstubs.o