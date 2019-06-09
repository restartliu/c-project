RPNcalcu:RPNcalcu.o stack.o change_type.o -lm

RPNcalcu.o:RPNcalcu.c stack.h
	gcc -c RPNcalcu.c

stack.o:stack.c stack.h
	gcc -c stack.c

change_type.o:change_type.c change_type.h
	gcc -c change_type.c

clean:
	rm -rf RPNcalcu *.o
