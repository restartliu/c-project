main:shell_sort.o main.o shell_sort.o
	gcc -o main shell_sort.o main.o shell_sort.h

shell_sort.o:shell_sort.c shell_sort.h
	gcc -c shell_sort.c

main.o:main.c shell_sort.h
	gcc -c main.c

clean:
	rm -rf *.o main
