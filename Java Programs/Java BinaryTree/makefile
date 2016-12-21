
CC = javac


exec: main.class BinaryTree.class Node.class
	java main


main.class: main.java
	$(CC) main.java

BinaryTree.class: BinaryTree.java
	$(CC) BinaryTree.java

Node.class: Node.java
	$(CC) Node.java

.PHONY: clean
clean: 
	rm -rf *.class 

