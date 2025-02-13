CXX      = g++
LD       = g++
CXXFLAGS = -std=c++17 -Wall -pedantic -O2 -O3

OUTPUT   = gen
TEST_OUTPUT = gen_test

MAIN_SOURCES = $(wildcard $(shell find src -name '*.cpp'))
TEST_SOURCES = $(filter-out ./src/main.cpp, $(wildcard $(shell find . -name '*.cpp')))

MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(MAIN_OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

$(TEST_OUTPUT): $(TEST_OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(wildcard $(shell find . -name '*.o')) $(OUTPUT) $(TEST_OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

test: $(TEST_OUTPUT)
	./$(TEST_OUTPUT)