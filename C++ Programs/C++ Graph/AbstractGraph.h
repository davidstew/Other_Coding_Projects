#ifndef ABSTRACTGRAPH_H
#define ABSTRACTGRAPH_H

#include "Graph.h"
#include <list>
#include <vector>
#include <iostream>
//using namespace std;

template <typename V>

class AbstractGraph : public GraphInterface<V>
{
  public:
	class Tree
	{
	  public:

	  Tree(int root, vector<int> parent, list<int> searchOrder, vector<int> verticies)
	  {
		this->root = root;
		this->parent = parent;
		this->searchOrder = searchOrder;
		this->verticies = verticies;
	  }

	  int getRoot() { return root; } //good
	  int getParent(int v) { return parent[this->getIndex(v)]; }
	  list<V> getSearchOrder() { return searchOrder; } //good
	  int getNumberOfVerticiesFound() { return searchOrder.size(); } //good

 	  void printPath(int vertex) //works
          {
	     vector<V> path = getPath(vertex);
	
	     cout << "A path from " << verticies[this->getIndex(root)] << " to " << verticies[this->getIndex(vertex)] << ": " << endl;

		for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " " ;

		cout << endl;
	  }

         void printTree()
	 {
		cout << "The Root is: " << verticies[this->getIndex(root)] << endl;
		cout << "Edges: ";
		for (int num = 0; num < parent.size(); num++)
		{
		  if (parent[num] != -1)
		  cout << "( " << verticies[this->getIndex(parent[num])] << ", " << verticies[num] << ")" << endl;
		}
	cout << endl;
	}

 	  
	  private:
	  int root;
	  vector<int> parent;
	  list<int> searchOrder;
	  vector<int> verticies;

	   vector<V> getPath(int vertex) 
           {
		vector<V> path;
	        do {

		   int index = getIndex(vertex);
		   path.push_back(verticies[index]);
	           vertex = parent[index];

  		} while (vertex != -1);
	   
         return path;
	}
        
   	int getIndex(V v)
	 {
	  std::vector<int>::iterator it = find(verticies.begin(), verticies.end(), v);
	  int pos =  distance(verticies.begin(), it);

	  return pos;
	 }
	
	};

	virtual void dummy() = 0; //makes the class abstract
	int getSize();
	vector<V> getVerticies();
	V getVertex(int index);
	int getIndex(V v);	
	list<V>* getNeighbors(int index);
	int getDegree(int num);
	void clear();
	void addVertex(V vertex);
	void addEdge(int u, int v);
	void printEdges();
	AbstractGraph<V>::Tree dfs(int vertex);
        AbstractGraph<V>::Tree bfs(int v);

  protected:
	vector<V> verticies; //vector of verticies
	vector< list<V>* > neighbors; //adjacency list
	AbstractGraph();
  	AbstractGraph(int edges [3][2], vector<V> verticies);
  private:
	void createAdjacencyLists(int edges [3][2], int NumberOfVerticies);
	void dfs(int v, vector<int>& parent, list<int>& searchOrder, bool isVisited[]);
};
   

#endif
