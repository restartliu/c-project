main:merge_sort.o main.o merge_sort.o
	gcc -o main merge_sort.o main.o merge_sort.h

merge_sort.o:merge_sort.c merge_sort.h
	gcc -c merge_sort.c

main.o:main.c merge_sort.h
	gcc -c main.c

clean:
	rm -rf *.o main
