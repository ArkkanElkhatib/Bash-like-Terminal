all: terminal 

terminal: terminal.o
	gcc terminal.o -o terminal

terminal.o: terminal.c
	gcc -c terminal.c

clean: 
	rm -rf *.o terminal
