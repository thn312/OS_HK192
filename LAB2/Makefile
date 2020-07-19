all: findsubstr.o readline.o main.o
	gcc findsubstr.o readline.o main.o -o mygrep
findsubstr.o: findsubstr.h findsubstr.c
	gcc -c findsubstr.c
readline.o: readline.h readline.c
	gcc -c readline.c
main.o: main.c findsubstr.h readline.h
	gcc -c main.c
clean:
	rm -f *.o
