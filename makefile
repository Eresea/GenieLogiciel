all: Projet

Projet: main.o MatCreuse.o
	g++ main.o MatCreuse.o -o Projet

main.o: main.cpp
	g++ -c main.cpp

MatCreuse.o: MatCreuse.cpp
	g++ -c MatCreuse.cpp

clean:
	rm *o Projet
