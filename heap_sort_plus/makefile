main:main.o heap_sort.o heap_sort.h

main.o:main.c heap_sort.h
	gcc -c main.c

heap_sort.o:heap_sort.c heap_sort.h
	gcc -c heap_sort.c

clean:
	rm -rf main *.o *.out *.gch
