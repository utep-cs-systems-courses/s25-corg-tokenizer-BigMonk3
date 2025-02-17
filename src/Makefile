CFLAGS=-g -O3 

all: main 

main: main.o
	cc $(CFLAGS) $^ -o $@ 
	
tester: tester.o
	cc $(CFLAGS) $^ -o $@ 
	
tester.o: tokenizer.h history.h
	cc -c tester.c 

clean:
	rm -f *.o tokenizer main
