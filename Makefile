CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic
OUTPUT   = gen.out

all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): gen.o Database.o
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)