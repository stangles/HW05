#include "ListGraph.h"

ListGraph::ListGraph(int numNodes)
{
}

ListGraph::~ListGraph()
{
}

//modifiers
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
}

//inspectors
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
}

unsigned ListGraph::degree(NodeID u) const
{
}

unsigned ListGraph::size() const
{
}

unsigned ListGraph::numEdges() const
{
}
