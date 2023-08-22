CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -fsanitize=address
OUTPUT   = gen.out

SOURCES = $(wildcard *.cpp */*.cpp)
OBJS    = $(SOURCES:.cpp=.o)

all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

stat: $(OUTPUT)
	./$(OUTPUT) -stat

update: $(OUTPUT)
	./$(OUTPUT) -update

i: $(OUTPUT)
	./$(OUTPUT) -interactive

clean:
	rm -f *.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)