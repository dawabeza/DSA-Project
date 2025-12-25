# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Ialgorithm -Ids

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Target executable name
TARGET = $(BINDIR)/supermarket

# List of source files (finds all .cpp files in src/)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Converts .cpp paths to .o paths in the obj/ folder
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Default rule
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@mkdir -p data

# Link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program
run: all
	./$(TARGET)

.PHONY: all directories clean run