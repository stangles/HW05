#include "ListGraph.h"

ListGraph::ListGraph(int numNodes)
{
	num_edges = 0;
	edgeList.resize(numNodes);
}

ListGraph::~ListGraph()
{
}

//modifier
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if((u >= 0 && u < edgeList.size()) && (v >= 0 && v < edgeList.size())) { //are u and v within bounds?
		if(u != v) {//does u equal v? keep nodes from connecting to self.
			if(weight > 0.0) { //is this a valid edge weight?
				EList::iterator it;
				bool found = false;
				for(it=edgeList[u].begin(); it != edgeList[u].end(); it++) { 
					if((*it).first == v)
						found = true;
				}
				if(!found) {//does an entry already exist?
					edgeList[u].push_front(NWPair(v, weight)); //add an NWPair with NodeID v and EdgeWeight weight
					edgeList[v].push_front(NWPair(u, weight)); //likewise, add it to the other node list
					num_edges++;
				}
			}
		}
	}
}

//begin inspectors
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	EList::const_iterator it;
	if((u >= 0 && u < edgeList.size()) && (v >= 0 && v < edgeList.size())) {
		for(it=edgeList[u].begin(); it != edgeList[u].end(); it++) {
			NWPair temp_check = *it;
			if(temp_check.first == v)
				return temp_check.second;
		}
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	std::list<NWPair> NWPList;
	if(u >= 0 && u < edgeList.size()) {
		NWPList = edgeList[u];
	}
	return NWPList;
}

unsigned ListGraph::degree(NodeID u) const
{
	int count = 0;
	if(u >= 0 && u < edgeList.size()) {
		EList::const_iterator it;
		for(it=edgeList[u].begin(); it != edgeList[u].end(); it++) {
			count++;
		}
	}
	return count;
}

unsigned ListGraph::size() const
{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const
{
	return num_edges;
}
