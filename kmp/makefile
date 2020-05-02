kmp:main.o kmp.o kmp.h

kmp.o:kmp.c kmp.h
	gcc -c kmp.c

main.o:main.c kmp.h
	gcc -c main.c

clean:
	rm -rf *.o kmp
