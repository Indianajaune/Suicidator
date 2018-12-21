
InfoSuicide: infosuicide.o main.o
	gcc -o infosuicide infosuicide.o main.o

infosuicide.o: infosuicide.c
	gcc -o infosuicide.o -c infosuicide.c -W -Wall -ansi -pedantic

main.o: main.c infosuicide.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf infosuicide
