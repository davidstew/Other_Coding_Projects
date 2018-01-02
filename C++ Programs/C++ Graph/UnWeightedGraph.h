#ifndef UNWEIGHTEDGRAPH_H
#define UNWEIGHTEDGRAPH_H

#include "Graph.h"
#include "AbstractGraph.h"
#include <list>
#include <vector>
using namespace std;

template <typename V>

class UnWeightedGraph : public AbstractGraph<V>
{
  public:
	void dummy();
	UnWeightedGraph();
	UnWeightedGraph(int edges [3][2], vector<V> verticies);

};

#endif
