movezero:main.o snowball.o snowball.h
	gcc -o movezero main.o snowball.o snowball.h

main.o:main.c snowball.h
	gcc -c main.c

snowball.o:snowball.c snowball.h
	gcc -c snowball.c

clean:
	rm -rf *.o movezero
