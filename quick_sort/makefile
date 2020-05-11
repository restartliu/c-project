main:quick_sort.o main.o quick_sort.o
	gcc -o main quick_sort.o main.o quick_sort.h

quick_sort.o:quick_sort.c quick_sort.h
	gcc -c quick_sort.c

main.o:main.c quick_sort.h
	gcc -c main.c

clean:
	rm -rf *.o main
