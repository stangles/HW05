#include "GraphAlgs.h"
#include "MatrixGraph.h"

int size;
int* bestTour = new int[size];
int* search_arr = new int[size];
Graph* graph;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	graph = G;
	size = graph->size();

	for(int i=0; i<size; i++) {
		bestTour[i] = i;
		search_arr[i] = i;
	}

	tour(search_arr,size,0);

	std::vector<NodeID> best (size);
	for(int i=0; i<size; i++) {
		best[i] = bestTour[i];
	}

	std::pair<std::vector<NodeID>, EdgeWeight > p (best, tour_length(bestTour));

	return p;
}

void tour(int* arr, int n, int startingPt)
{
	if((n-startingPt)==1) {
		if(tour_length(arr) < tour_length(bestTour))
			bestTour = arr;
	} else {
		for(int i=startingPt; i<n; i++) {
			swap(arr,startingPt,i);
			tour(arr,n,startingPt+1);
			swap(arr,startingPt,i);
		}
	}
}

void swap(int* arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

EdgeWeight tour_length(int* tour)
{
	EdgeWeight length = 0.0;
	for(int i=0; i<size-1; i++) {
		length += graph->weight(tour[i],tour[i+1]);
	}
	length += graph->weight(tour[size-1], tour[0]);

	return length;
}