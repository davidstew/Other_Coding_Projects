
exec: AbstractGraph.o UnWeightedGraph.o main.o
	g++ -std=c++11 -o program AbstractGraph.o UnWeightedGraph.o main.o
	./program

AbstractGraph.o: Graph.h AbstractGraph.h AbstractGraph.cpp
	g++ -c -std=c++11 Graph.h AbstractGraph.h AbstractGraph.cpp

UnWeightedGraph.o: UnWeightedGraph.h UnWeightedGraph.cpp
	g++ -c -std=c++11 UnWeightedGraph.h UnWeightedGraph.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

.PHONY:
clean:
	rm -rf *.o program
