conversion:conversion.o stack.o

conversion.o:conversion.c
	gcc -c conversion.c

stack.o:stack.c stack.h
	gcc -c stack.c stack.h

clean:
	rm -rf *.out conversion *.o *.h.gch
