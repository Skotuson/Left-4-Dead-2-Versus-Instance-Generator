CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic
OUTPUT   = gen.out

all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): gen.o Database.o Helper.o Generator.o
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

stat: $(OUTPUT)
	./$(OUTPUT) -stat

update: $(OUTPUT)
	./$(OUTPUT) -update

clean:
	rm -f *.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)