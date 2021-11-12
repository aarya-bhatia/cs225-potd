EXENAME = main
OBJS = main.o Swiftcipher.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

OBJS=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
