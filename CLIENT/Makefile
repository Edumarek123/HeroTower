.PHONY: all


SOURCEFILES = $(shell find -type f -regex ".*\.cpp")
OBJECTFILES = $(patsubst %.cpp, %.o, $(SOURCEFILES))
TARGET = bin/client

CXX = g++
CXXFLAGS = -g -Wall
SDLFLAGS = -lSDL2main -lSDL2 -lSDL2_image
NETFLAGS = -lenet

all: clean build run

build: $(TARGET) send

run: 
	./$(TARGET)

leak: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./$(TARGET)

send:
	./scp.sh

$(TARGET): $(OBJECTFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDLFLAGS) $(NETFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJECTFILES) $(TARGET) 


