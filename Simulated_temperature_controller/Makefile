# Compiler
CXX = g++

# Compile flags
CXXFLAGS = -std=c++11 -Wall

# Link flags
LDFLAGS = -lpthread

# Source files and objects
SRCS = main.cpp TempSensor.cpp Actuator.cpp Controller.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = program

# Compile and link the program
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
