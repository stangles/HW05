/*
 * Exhaustive path search method described in lecture on 11/20
 */
#include "GraphAlgs.h"
#include "MatrixGraph.h"

int size;
EdgeWeight worst_tour;
NodeID* best_tour = new NodeID[size];
NodeID* search_arr = new NodeID[size];
Graph* graph;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	graph = G;
	size = graph->size();

	for(int i=0; i<size; i++) {
		best_tour[i] = i;
		search_arr[i] = i;
	}

	worst_tour = tour_length(best_tour,size);

	tour(search_arr,size,0);

	std::vector<NodeID> best (size);
	for(int i=0; i<size; i++) {
		best[i] = best_tour[i];
	}

	std::pair<std::vector<NodeID>, EdgeWeight > p (best, tour_length(best_tour,size));

	return p;
}

void tour(NodeID* arr, int n, int startingPt)
{
	if((n-startingPt)==1) {
		if(tour_length(arr,size) < tour_length(best_tour,size))
			best_tour = arr;
	} else {
		for(int i=startingPt; i<n; i++) {
			swap(arr,startingPt,i);
			tour(arr,n,startingPt+1);
			swap(arr,startingPt,i);
		}
	}
}

void swap(NodeID* arr, int index1, int index2)
{
	NodeID temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

EdgeWeight tour_length(NodeID* tour, int arr_length)
{
	EdgeWeight length = 0.0;
	for(int i=0; i<arr_length-1; i++) {
		length += graph->weight(tour[i],tour[i+1]);
	}
	length += graph->weight(tour[arr_length-1], tour[0]);

	return length;
}