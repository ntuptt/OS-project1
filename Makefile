# CFLAG = -DDEBUG -Wall -std=c++17
CFLAG = -Wall -std=c++17

main: main.o scheduler.o util.o
	g++ $(CFLAG) main.o scheduler.o util.o -o main
main.o: main.cpp Makefile
	g++ $(CFLAG) main.cpp -c
scheduler.o: scheduler.cpp scheduler.h Makefile
	g++ $(CFLAG) scheduler.cpp -c
util.o: util.cpp util.h Makefile
	g++ $(CFLAG) util.cpp -c
clean:
	rm -rf *o main
