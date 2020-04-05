main: tasks.o
	g++ -o main main.cpp tasks.o
tasks:
	g++ -o tasks.cpp
clean:
	rm *.o main
