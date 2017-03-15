CXX ?= g++

CXXFLAGS += -Wall -Iinclude/ -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all doc

all:
	$(CXX) src/*.cpp $(CXXFLAGS)

doc:
	doxygen Doxyfile
