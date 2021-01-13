parse:jsonParse.h jsonParse.o main.o
	gcc -o parse main.o jsonParse.o

main.o:main.c jsonParse.h
	gcc -c main.c

jsonParse.o:jsonParse.h jsonParse.c
	gcc -c jsonParse.c

clean:
	rm -rf *.o parse *.gch *.out release

debug:
	gcc -g -o release main.c jsonParse.c jsonParse.h
