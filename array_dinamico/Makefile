CC = gcc -Wall -pedantic

build:
	mkdir -p build

array_dinamico.o: build array_dinamico.c 
	$(CC) array_dinamico.c -c -o build/array_dinamico.o
	$(CC) element.c -c -o build/element.o

main: build array_dinamico.o main.c
	$(CC) main.c build/array_dinamico.o build/element.o -o build/main

clean:
	rm -rf build

run: main
	./build/main
