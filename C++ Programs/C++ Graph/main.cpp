#include <iostream>
#include "Graph.h"
#include "AbstractGraph.h"
#include "AbstractGraph.cpp"
#include "UnWeightedGraph.h"
#include "UnWeightedGraph.cpp"
#include <list>

using namespace std;

int main()
{
	//int edges [3][2] = { {2,10}, {2,25}, {2, 37} };

	//vector<int> verticies;
	//verticies.push_back(2);
	//verticies.push_back(10);
	//verticies.push_back(25);
	//verticies.push_back(37);


	//UnWeightedGraph<int>lol(edges,verticies);
	UnWeightedGraph<int> lol; //invokes default constructor, dont use parenthesis or errors occur

	lol.addVertex(16);
	lol.addVertex(13);
	lol.addVertex(167);	
	lol.addVertex(18);
	lol.addVertex(27);

	lol.addEdge(16,167);
	lol.addEdge(16,13);
	lol.addEdge(16,18);
	lol.addEdge(167,18);
	lol.addEdge(13,18);
	lol.addEdge(167,27);

	lol.printEdges();
	
	cout << endl << endl;
	
	cout << "Depth First Search" << endl;

	lol.dfs(27).printTree(); //prints accordingly, depedent on the adjacency list

	cout << "Breadth First Search" << endl;

	lol.bfs(27).printTree(); //prints accordingly, depedent on the adjacency list

	/*
	cout << "dfs " << endl;

	list<int> lol1 = lol.dfs(27).getSearchOrder();

	typename std::list<int>::iterator it1 = lol1.begin();
	
	for (; it1 != lol1.end(); ++it1)
	{
		cout << *it1 << " ";
	}

	cout << endl; 

	cout << "bfs " << endl;
	list<int> lol2 = lol.bfs(27).getSearchOrder();

	typename std::list<int>::iterator it = lol2.begin();
	
	for (; it != lol2.end(); ++it)
	{
		cout << *it << " ";
	}
	*/

	/*
	list<int>* v = lol.getNeighbors(13);
	
	typename std::list<int>::iterator it = v->begin();
	
	for (; it != v->end(); ++it)
	{
		cout << *it << endl;
	}


	cout << lol.getIndex(0) << endl;

	cout << lol.getDegree(0) << endl;

	list<int>* v = lol.getNeighbors(0);

	typename std::list<int>::iterator it = v->begin();
	
	for (; it != v->end(); ++it)
	{
		cout << *it << endl;
	}
	
	cout << lol.getSize() << endl;

	vector<int> q = lol.getVerticies();

	cout << q[0] << endl;

	int x = lol.getVertex(2);

	cout << x << endl;
	*/


	return 0;

}
