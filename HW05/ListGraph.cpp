#include "ListGraph.h"

ListGraph::ListGraph(int numNodes)
{
}

ListGraph::~ListGraph()
{
}

//modifier
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
}

//begin inspectors
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	return std::list<NWPair> ();
}

unsigned ListGraph::degree(NodeID u) const
{
	return 0.0;
}

unsigned ListGraph::size() const
{
	return 0.0;
}

unsigned ListGraph::numEdges() const
{
	return 0.0;
}
