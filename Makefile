#Gavan Adrian George - 324CA

run: Main
	./Main

build: Main

Main: Main.o
	g++ -Wall -O3 Main.o -o Main

Main.o: Main.cpp
	g++ -Wall -O3 -c Main.cpp

clean:
	rm -f *.o
	rm -f Main
	rm -f *.out
