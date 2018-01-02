CC = gcc

exec: main.o BinaryTree.o
	$(CC) main.o BinaryTree.o -o output
	./output

main.o: main.c
	$(CC) -c main.c

BinaryTree.o: BinaryTree.h BinaryTree.c
	$(CC) -c BinaryTree.c

.PHONY: clean
clean:
	rm -rf *.o output
	
