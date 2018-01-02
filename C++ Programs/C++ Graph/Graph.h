#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include <list>
#include <vector>
using namespace std;

template <typename V>
class GraphInterface
{

public:
	virtual int getSize() = 0;
	virtual vector<V> getVerticies() = 0;
	virtual V getVertex(int index) = 0;
	virtual int getIndex(V v) = 0;
	virtual list<V>* getNeighbors(int index) = 0;
	virtual int getDegree(int v) = 0;
	virtual void printEdges() = 0;
	virtual void clear() = 0; 
	virtual void addVertex(V vertex) = 0;
	virtual void addEdge(int u, int v) = 0;
};

#endif
