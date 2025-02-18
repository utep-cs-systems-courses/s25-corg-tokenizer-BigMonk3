CFLAGS=-g -O3 

all: ui 

main: ui.o
	cc $(CFLAGS) $^ -o $@ 
	
tester: tester.o
	cc $(CFLAGS) $^ -o $@ 
	
tester.o: tokenizer.h history.h
	cc -c tester.c 

clean:
	rm -f *.o tokenizer ui
