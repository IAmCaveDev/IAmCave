CXX ?= g++

CXXFLAGS = -Wall -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CXX) ./src/*.cpp $(CXXFLAGS)
