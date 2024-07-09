# Makefile for Car Racing Game

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -Wextra -I..

# Source files
SOURCES = main.cpp ../Car.cpp ../CarSport.cpp ../CarSdv.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = car_racing_game

# Default target
all: $(EXECUTABLE)

# Link the program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp
main.o: main.cpp ../Car.hpp ../PrintHeader.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

# Phony targets
.PHONY: all clean
