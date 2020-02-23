RPNcalcu:RPNcalcu.o stack.o -lm

RPNcalcu.o:RPNcalcu.c stack.h
	gcc -g -c RPNcalcu.c

stack.o:stack.c stack.h
	gcc -c stack.c

clean:
	rm -rf RPNcalcu *.o *.h.gch *.out

test:
	gcc -g RPNcalcu.c stack.c stack.h -lm
