CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic
LIBRARY_PATH=../static_library
LIBRARY=-L$(LIBRARY_PATH) -lsearch_library
INCLUDE=-I$(LIBRARY_PATH)

all: app

app: main.o
	$(CXX) $(CXXFLAGS) main.o -o app $(LIBRARY)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c main.cpp -o main.o

clean:
	del app main.o
