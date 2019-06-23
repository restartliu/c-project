main:main.o merge_sort.o

main.o:main.c merge_sort.h
	gcc -c main.c

merge_sort.o:merge_sort.c merge_sort.h
	gcc -c merge_sort.c

clean:
	rm -rf main *.o
