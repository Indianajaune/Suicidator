InfoSuicide: infosuicide.o main.o
	gcc -o infosuicide infosuicide.o ./libcsv/libcsv_la-libcsv.o  main.o -W -Wall -ansi -pedantic -std=c11

infosuicide.o: infosuicide.c
	gcc -o infosuicide.o -c infosuicide.c ./libcsv/libcsv_la-libcsv.o  -W -Wall -ansi -pedantic -std=c11

main.o: main.c infosuicide.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic -std=c11

clean:
	rm -rf *.o

mrproper: clean
	rm -rf infosuicide
