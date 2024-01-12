# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -std=c++11 -Iheader

# Source files
SOURCES = $(wildcard src/*.cpp)

# Object files
OBJECTS = $(patsubst src/%.cpp,bin/%.o,$(SOURCES))

# Executable name
EXECUTABLE = bin/library

.PHONY: all clean

# Default make
all: $(EXECUTABLE)
	@echo "Library compiled."

# Linking the executable from the object files
$(EXECUTABLE): $(OBJECTS) | bin
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compiling source files to object files
bin/%.o: src/%.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
bin:
	mkdir -p bin

# Cleaning up the build
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -rf bin

