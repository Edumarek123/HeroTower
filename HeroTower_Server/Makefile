.PHONY: all

SOURCEFILES = $(shell find -type f -regex ".*\.cpp") 
OBJECTFILES = $(patsubst %.cpp, %.o, $(SOURCEFILES))
TARGET = server

CXX = g++
CXXFLAGS = -g -Wall -lenet -O2 -lboost_iostreams -lboost_serialization

all: clean build run

build: $(TARGET)

run: 
	./$(TARGET)

$(TARGET): $(OBJECTFILES)
	$(CXX) -o $@ $^ $(CXXFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJECTFILES) $(TARGET)


