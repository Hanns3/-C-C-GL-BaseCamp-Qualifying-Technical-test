CXX=g++
CXXFLAGS=-std=c++17 -lstdc++fs -Wall -Wextra -pedantic

all: search_library

search_library: search_library.o
	ar rcs libsearch_library.a search_library.o

search_library.o: search_library.cpp search_library.h
	$(CXX) $(CXXFLAGS) -c search_library.cpp

clean:
	del *.o *.a
