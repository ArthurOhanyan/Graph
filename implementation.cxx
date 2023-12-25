#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph(int x) : vec(x, std::vector<int>()){}
void Graph::add_vertex (int vertex)
	{
		vec.push_back(std::vector<int>());
		std::cout << " added - " << vec.size() << " vertex " << std::endl;
	}

void Graph::add_edges (int vertex, int vertex2)
	{
		if (vertex < 0 || vertex >= vec.size() || vertex2 < 0 || vertex >= vec.size()){
			
			return;
		}

		auto it = std::find(vec[vertex].begin(),vec[vertex].end(),vertex2);
		if (it == vec[vertex].end()){

			vec[vertex].push_back(vertex2);
		}
	}

void Graph::remove_vertex(int vertex)
{
	if (vertex < 0 || vertex >= vec.size()){
		
		std::cout << " INVALID VERTEX !!! " << std::endl;
		return;
	}

	for (int i = 0; i < vec.size(); ++i){
		
		vec[i].erase(std::remove(vec[i].begin(),vec[i].end(),vertex),vec[i].end());
	}
	
	vec.erase(vec.begin() + vertex);
	for (int i = 0; i < vec.size(); ++i){
		
		reset_values(vec[i],vertex);
		//std::cout << " ???? " << std::endl;
	}

	//vec.erase(vec.begin() + vertex);
	std::cout << " removed the vertex " << vertex << std::endl;
}

void Graph::remove_edges (int vertex, int vertex2)
{
	if (vertex < 0 || vertex >= vec.size() || vertex2 < 0 || vertex2 >= vec.size()){
		
		std::cout << " INVALID VERTEXS " << std::endl;
		return;
	}
	
	auto it =  std::find(vec[vertex].begin(), vec[vertex].end(), vertex2);
	if (it != vec[vertex].end()){
		
		vec[vertex].erase(it);
	}

	it = std::find(vec[vertex2].begin(), vec[vertex2].end(), vertex);
	if (it != vec[vertex2].end()){
		
		vec[vertex2].erase(it);
	}

}


void Graph::reset_values(std::vector<int>& m_vec, int val)
{
	
	for (int i = 0; i < m_vec.size(); ++i){
		
		if (m_vec[i] > val){
			
			--m_vec[i];
		}
	}
}

void Graph::get_neighbors(int vertex)
{
	if (vertex < 0 || vertex >= vec.size()){
		
		std::cout << " INVALID VERTEX " << std::endl;
		return;
	}

	std::cout << " vec[" << vertex << "] 's neighbors is : ";
	for (int i = 0; i < vec[vertex].size(); ++i){
		
		std::cout << " " << vec[vertex][i] ;
	}
	std::cout << std::endl;
}

bool Graph::has_edges(int vertex, int vertex2)
{
	if (vertex < 0 || vertex >= vec.size() || vertex2 < 0 || vertex2 >= vec.size()){
		
		std::cout << " INVALID VERTEX " << std::endl;
		return false;
	}

	bool vec1 = false;
	bool vec2 = false;

	for (int i = 0; i < vec[vertex].size(); ++i){
		
		if (vec[vertex][i] == vertex2){
			
			vec1 = true;
			break;
		}
	}

	for (int i = 0; i < vec[vertex2].size(); ++i){
	
		if (vec[vertex2][i] == vertex){
			
			vec2 = true;
			break;
		}	
	}

	if (vec1){
		
		std::cout << " exist edges from " << vertex << " to " << vertex2 << std::endl;
	}
	if (vec2){
		
		std::cout << " exist edges from " << vertex2 << " to " << vertex << std::endl;
	}

	if (vec1 || vec2){
	
		return true;
	}
	return false;

}

bool Graph::has_vertex(int vertex)
{
	if (vertex < 0 || vertex >= vec.size()){
		
		std::cout << " INVALID VERTEX " << std::endl;
		return false;
	}

			
	std::cout << " The vertex exist , and it's neighbors is : ";
	get_neighbors(vertex);
	return true;
	


}

int Graph::vertex_count()
{
	return vec.size();
}

int Graph::edges_count()
{
	int count = 0;
	for (int i = 0; i < vec.size(); ++i){
		
		count += vec[i].size();
	}

	return count;
}


void Graph::print (){
		
		for (int i = 0; i < vec.size(); ++i){
			
			std::cout << " " << i << " -> ";
			for(int j = 0; j < vec[i].size(); ++j){
				
				std::cout << " " << vec[i][j];
			}
			std::cout << std::endl;
		}
}

