objs = RPNcalcu.o stack.o

RPNcalcu:$(objs)
	cc -o RPNcalcu $(objs) -lm

$(objs):stack.h

test:
	gcc -o test -g $(objs) -lm

.PHONY:clean
clean:
	rm -rf RPNcalcu test $(objs) *.h.gch *.out
