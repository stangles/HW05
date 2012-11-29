#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	num_edges = 0;
	M.resize(num_nodes, std::vector<EdgeWeight>(num_nodes, 0.0));
	//M = std::vector<std::vector<EdgeWeight> > (num_nodes, std::vector<EdgeWeight>(num_nodes, 0));
	//std::vector<std::vector<EdgeWeight> > M (num_nodes, std::vector<EdgeWeight>(num_nodes));
}

MatrixGraph::~MatrixGraph()
{
}

//modifier
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if((u >= 0 && u < M.size()) && (v >= 0 && v < M.size())) { //are u and v within bounds?
		if(u != v) {//does u equal v? keep nodes from connecting to self.
			if(M.at(u).at(v) == 0.0) { //does an edge exist already?
				if(weight > 0.0) { //is this a valid edge weight?
					M[u][v] = weight; //will I ever stop asking questions?
					M[v][u] = weight;
					num_edges++;
				}
			}
		}
	}
}

//begin inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	if((u >= 0 && u < this->size()) && (v >= 0 && v < this->size())) 
		return M.at(u).at(v);
	else 
		return 0.0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{
	std::list<NWPair> l;
	return l;
}

unsigned MatrixGraph::degree(NodeID u) const
{
	return 0;
}

unsigned MatrixGraph::size() const
{
	return M.size();
}

unsigned MatrixGraph::numEdges() const
{
	return num_edges;
}
