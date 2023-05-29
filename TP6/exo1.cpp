#include <iostream>
#include <time.h>
#include <cstdlib>
#include "../lib/graph.h"

using namespace std; 

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
	 for (int i = 0 ; i < nodeCount ; i++ ){
		this->appendNewNode(new GraphNode(i));
	 }
	 for (int i = 0 ; i < nodeCount ; i++){
		for (int j = 0 ; j < nodeCount ; j++){
			if (adjacencies[i][j] != 0){
				this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
			}
		}
	 }
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	  */
	visited[first->value] = true;
	for (Edge *e = first->edges ; e != NULL ; e = e->next){
		if (!visited[e->destination->value]){
			nodes[nodesSize] = e->destination;
			nodesSize++;
			deepTravel(e->destination, nodes, nodesSize, visited);
		}
	}
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	while(!nodeQueue.empty()){
		GraphNode* v = nodeQueue.front();
		nodeQueue.pop();
		visited[v->value] = true;
		nodes[nodesSize] = v;
		nodesSize++;
		for (Edge *e = v->edges ; e != NULL ; e = e->next){
			if (!visited[e->destination->value]){
				nodeQueue.push(e->destination);
			}
	}
	}

}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
	visited[first->value] = true;
	for (Edge *e = first->edges ; e != NULL ; e = e->next){
		if (!visited[e->destination->value]){
			if (detectCycle(e->destination, visited)){
				return true;
			}
		}
		else{
			return true;
		}
	}
    return false;
}



void drawMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
	cout << endl;
}








int main(int argc, char *argv[])
{
	int n=7;
    int** matrix = new int*[n];
    for (int i=0; i<n; ++i)
	{
        matrix[i] = new int[n];
        for (int j=0; j<n; ++j)
		{
			matrix[i][j] = (rand() % 300 - 230) / 2;
			if (matrix[i][j] < 0)
				matrix[i][j] = 0;
		}
	}

	//------------------
	//drawMatrix(matrix, n);


	//------------------
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;


	return 0;
}















// void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
// {
//     for (int i=0 ; i<nodeCount ; i++) {
//         this->appendNewNode(new GraphNode(i));
//     }

//     for (int i=0 ; i<nodeCount ; i++) {
//         for (int j=0 ; j<nodeCount ; j++) {
//             if (adjacencies[i][j] != 0) {
//                 this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
//             }
//         }
//     }
// }

// void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
// {
//     visited[first->value] = true;
//     for (Edge *e = first->edges ; e != nullptr ; e = e->next){
//         if (!visited[e->destination->value]){
//             nodes[nodesSize] = e->destination;
//             nodesSize++;
//             deepTravel(e->destination, nodes, nodesSize, visited);
//         }
//     }
// }


// void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
// {
//     /**
//      * Fill nodes array by travelling graph starting from first and using queue
//      * nodeQueue.push(a_node)
//      * nodeQueue.front() -> first node of the queue
//      * nodeQueue.pop() -> remove first node of the queue
//      * nodeQueue.size() -> size of the queue
//      */
//     std::queue<GraphNode*> nodeQueue;
//     nodeQueue.push(first);
//     while (!nodeQueue.empty()) {
//         GraphNode* node = nodeQueue.front();
//         nodeQueue.pop();
//         nodes[nodesSize] = node;
//         nodesSize++;
//         visited[node->value] = true;

//         Edge* edge = node->edges;
//         while (edge != nullptr) {
//             if (!visited[edge->destination->value]) {
//                 nodeQueue.push(edge->destination);
//             }
//             edge = edge->next;
//         }
//     }
// }

// bool Graph::detectCycle(GraphNode *first, bool visited[])
// {
//     visited[first->value] = true;
//     for (Edge *e = first->edges ; e != nullptr ; e = e->next){
//         if (!visited[e->destination->value]){
//             if (detectCycle(e->destination, visited)){
//                 return true;
//             }
//         }
//         else{
//             return true;
//         }
//     }
//     return false;
// }




