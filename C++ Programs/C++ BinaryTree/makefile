output: main.o BinaryTree.o
	g++ main.o BinaryTree.o -o output

main.o: main.cpp
	g++ -c main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

clean:
	rm *.o output
