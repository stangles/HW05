#include "GraphAlgs.h"
#include "MatrixGraph.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	int size = G->size();
	G = new MatrixGraph(size);

	int* bestTour = new int[size];
	int* arr = new int[size];
	for(int i=0; i<size; i++) {
		bestTour[i] = i;
		arr[i] = i;
	}

	
}

void tour(int* arr, int n, int startingPt)
{
	if((n-startingPt)==1) {

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