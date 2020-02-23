main:main.o RBtree.o RBtree.h

main.o:main.c RBtree.h
	gcc -c main.c

RBtree.o:RBtree.c RBtree.h
	gcc -c RBtree.c

clean:
	rm -rf *.o main
