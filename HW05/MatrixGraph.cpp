#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_edges)
{
}

MatrixGraph::~MatrixGraph()
{
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
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
	return 0;
}

unsigned MatrixGraph::numEdges() const
{
	return num_edges;
}
