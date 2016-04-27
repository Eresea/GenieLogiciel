all: Projet

Projet: main.o matcreuse.o
	g++ main.o matcreuse.o -o Projet

main.o: main.cpp
	g++ -c main.cpp

matcreuse.o: matcreuse.cpp
	g++ -c matcreuse.cpp

clean:
	rm *o Projet
