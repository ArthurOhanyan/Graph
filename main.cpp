#include <iostream>
#include "prototype.h"


int main()
{
	Graph obj(5);
	obj.add_edges(0,1);
	obj.add_edges(0,2);
	obj.add_edges(0,3);
	obj.add_edges(0,5);
	obj.add_edges(1,3);
	obj.add_edges(1,0);
	obj.add_edges(1,5);
	obj.add_edges(2,1);
	obj.add_edges(2,0);
	obj.add_edges(2,3);
	obj.add_edges(2,5);
	obj.add_edges(3,4);
	obj.add_edges(3,0);
	obj.add_edges(3,2);
	obj.add_edges(4,0);
	obj.add_edges(4,2);
	obj.add_edges(4,5);
	obj.add_edges(5,2);
	obj.print();
	std::cout << std::endl;
	obj.add_vertex(6);
	obj.add_edges(5,4);
	obj.add_edges(4,3);
	obj.add_edges(5,3);
	obj.add_edges(3,5);
	obj.print();
	std::cout << std::endl;
	obj.remove_vertex(3);
	obj.print();
	//std::cout << std::endl;
	//obj.remove_edges(2,0);
	//obj.print();
	obj.get_neighbors(3);
	obj.has_edges(1,4);
	obj.has_vertex(2);
	std::cout << "The vertex count is : " <<  obj.vertex_count() << std::endl;
	std::cout << "The edges count is : " << obj.edges_count() << std::endl;
	
}
