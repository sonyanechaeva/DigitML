:WARNINGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wformat=2\
 -Winit-self -Wmissing-declarations -Wredundant-decls -Wshadow\
 -Wstrict-overflow=5 -Wswitch-default -Wundef

FLAGS = $(WARNINGS) -std=c++11

SRC = src/main.cpp

sigmoid: 
	g++ $(FLAGS) -Ofast $(SRC) -I include -o main

bent_identity:
	g++ $(FLAGS) -DPERS -Ofast $(SRC) -I include -o main

test:
	g++ $(FLAGS) -DTESTS -Ofast $(SRC) -I include -o main -lgtest

all: sigmoid

debug:
	g++ $(FLAGS) -DDEBUG $(SRC) -o main
	./main

CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread


test: test_activations.cpp fractional_activation.h heaviside_activation.h
	$(CXX) $(CXXFLAGS) -o test_program test_activations.cpp $(GTEST_FLAGS)
	./test_program
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I. -Igtest/include
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Цель для компиляции тестов
test: test_activations.cpp fractional_activation.h heaviside_activation.h
	$(CXX) $(CXXFLAGS) -o test_program test_activations.cpp $(GTEST_LIBS)

# Цель для запуска тестов
run-tests: test
	./test_program

# Цель для очистки
clean:
	rm -f test_program *.o
