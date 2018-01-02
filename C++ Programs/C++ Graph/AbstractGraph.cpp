#include "AbstractGraph.h"
#include "Graph.h"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
using std::list;

template <typename V>
AbstractGraph<V>::AbstractGraph()
{
	
}

template <typename V>
AbstractGraph<V>::AbstractGraph(int edges [3][2],  vector<V> verticies)
{
	cout << "whats poppin" << endl;

	for (int i = 0; i < verticies.size(); i++)
	this->verticies.push_back(verticies[i]);

	createAdjacencyLists(edges, verticies.size());
	
}

template <typename V>
void AbstractGraph<V>::createAdjacencyLists(int edges[3][2], int NumberOfVerticies)
{
	cout << "sup" << endl;
	
	for (int num = 0; num < NumberOfVerticies; num++)
	{
		cout << "lmao" << endl;
		neighbors.push_back(new list<V>);
		
	}
	
	for (int i = 0; i < 3; i++)
	{
	   cout << "orale" << endl;
	   int u = edges[i][0];
	   int v = edges[i][1];
	   neighbors[u]->push_back(v); 
	}

}

//@override
template <typename V>
int AbstractGraph<V>::getSize()
{
  return verticies.size();
}

//@override
template <typename V>
vector<V> AbstractGraph<V>::getVerticies()
{
	return verticies;
}


//@override
template <typename V>
V AbstractGraph<V>::getVertex(int index)
{
	return verticies.at(index);
}


//@override
template <typename V>
int AbstractGraph<V>::getIndex(V v)
{
	std::vector<int>::iterator it = find(verticies.begin(), verticies.end(), v);
	int pos =  distance(verticies.begin(), it);

	return pos;
}

//@override
template <typename V>
list<V>* AbstractGraph<V>::getNeighbors(int vertex)
{
	return neighbors[this->getIndex(vertex)];
}

//@override
template <typename V>
int AbstractGraph<V>::getDegree(int vertex)
{
	return neighbors[this->getIndex(vertex)]->size();
}

template <typename V>
void AbstractGraph<V>::clear()
{
	verticies.clear();
	neighbors.clear();
}

template <typename V>
void AbstractGraph<V>::addVertex(V vertex)
{
	verticies.push_back(vertex);
	neighbors.push_back(new list<V>);
}


template <typename V>
void AbstractGraph<V>::addEdge(int u, int v)
{
	neighbors[this->getIndex(u)]->push_back(v);
	neighbors[this->getIndex(v)]->push_back(u);
	
}


template <typename V>
void AbstractGraph<V>::printEdges()
{	
	
	for (int num = 0; num < verticies.size(); num++)
	{
	  cout << "For vertex: " << verticies[num] << " the edges are: " << endl;

	  typename std::list<int>::iterator it = neighbors[num]->begin();
	
	  for (; it != neighbors[num]->end(); ++it)
	  {
		cout << *it << endl;
	  }
	}
}

template <typename V>
typename AbstractGraph<V>::Tree AbstractGraph<V>::dfs(int v)
{
  
  list<int> searchOrder;
  vector<int> parent(verticies.size());

  for (int num = 0; num < parent.size(); num++)
  {
	parent[num] = -1; // make all parents = -1
  }

  bool isVisited[verticies.size()] = { 0 }; //all false

  dfs(v, parent, searchOrder, isVisited); //invoke recursion

  return AbstractGraph<V>::Tree(v, parent, searchOrder, verticies);

}

template <typename V>
void AbstractGraph<V>::dfs(int v, vector<int>& parent, list<int>& searchOrder, bool isVisited[])
{
  
  searchOrder.push_back(v); 
  isVisited[this->getIndex(v)] = true;
   
  
  for (auto it = neighbors[this->getIndex(v)]->begin(); it != neighbors[this->getIndex(v)]->end   (); ++it)
  {

	if (isVisited[this->getIndex(*it)] == false)
	 {
	  parent[this->getIndex(v)] = *it;
	  dfs(*it, parent, searchOrder, isVisited);
	}
  } 
}

//breadth first search
template <typename V>
typename AbstractGraph<V>::Tree AbstractGraph<V>::bfs(int vertex)
{

   list<V> searchOrder;
   vector<int> parent(verticies.size());
   
    for (int num = 0; num < parent.size(); num++)
    {
	parent[num] = -1; // make all parents = -1
    }	  
 
    deque<int> Queue;
    
    bool isVisited[verticies.size()] = { 0 };

    Queue.push_back(vertex);

    isVisited[this->getIndex(vertex)] = true;
    
    while (!Queue.empty())
    {
	int v = Queue.front();
	Queue.pop_front();
	searchOrder.push_back(v);
 	
	for (auto it = neighbors[this->getIndex(v)]->begin(); it != neighbors[this->getIndex(v)]->end(); ++it)
  	{

	  if (isVisited[this->getIndex(*it)] == false)
	  {
	    Queue.push_back(*it);
	    parent[this->getIndex(*it)] = v;
	    isVisited[this->getIndex(*it)] = true;
	  }
  	} 
    }

return AbstractGraph<V>::Tree(vertex, parent, searchOrder, verticies);	
}


