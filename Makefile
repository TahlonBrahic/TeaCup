all: TeaCup

TeaCup: compiler.c
	gcc -o TeaCup compiler.c

clean:
	rm -f TeaCup