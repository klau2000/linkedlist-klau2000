all: main.o linkedlist.o
	gcc -o output main.o linkedlist.o

main.o: main.c linkedlist.c
	gcc -c main.c

linkedlist.o: linkedlist.c headers.h
	gcc -c linkedlist.c

headers.o: headers.c headers.h
	gcc -c headers.c

run:
	./output

clean:
	rm *.o
	rm *~
