#Makefile

FLAGS = -pedantic-errors -std=c++11

setup.o: setup.cpp setup.h
	g++ $(FLAGS) -c $<
players.o: players.cpp players.h
	g++ $(FLAGS) -c $<
game.o: game.cpp game.h
	g++ $(FLAGS) -c $<
main.o: main.cpp game.h players.h setup.h
	g++ $(FLAGS) -c $<
main: game.o setup.o players.o main.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main.o game.o setup.o players.o main

.PHONY: clean