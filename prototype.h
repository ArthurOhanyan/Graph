#include <iostream>
#include <vector>
#include <algorithm>

class Graph 
{
	std::vector<std::vector<int>> vec;
	void reset_values(std::vector<int>&, int);
public:
	Graph(int);
	
	void add_vertex(int);
	void add_edges (int, int);
	void remove_vertex(int);
	void remove_edges(int,int);
	void get_neighbors(int);
	bool has_edges(int,int);
	bool has_vertex(int);
	int vertex_count();
	int edges_count();
	void print ();
};

#include "implementation.cxx"
