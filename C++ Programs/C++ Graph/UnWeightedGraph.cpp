#include "Graph.h"
#include "UnWeightedGraph.h"
#include "AbstractGraph.h"
#include <iostream>
using namespace std;

template <typename V>
void UnWeightedGraph<V>::dummy()
{

}

template <typename V>
UnWeightedGraph<V>::UnWeightedGraph() : AbstractGraph<V>::AbstractGraph() //call the superclass constructor, inheritance always works this way
{
	
}

template <typename V>
UnWeightedGraph<V>::UnWeightedGraph(int edges[3][2], vector<V> verticies) : AbstractGraph<V>::AbstractGraph(edges, verticies) //call the superclass constructor, inheritance always works this way
{
	

}
