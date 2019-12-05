/* Maylee Gagnon
 * CS 2223 HW5P4
 * 11.26.2019
 */
#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;

#define sizeOfGraph 10

/* Vertex left in Q/not visited yet with the minimum distance
 *
 */
int minDist(int d[sizeOfGraph], bool visited[sizeOfGraph]){
	int min = INT_MAX;
	int minPos = 0;

	for (int i = 0; i < sizeOfGraph; i++){
		if (visited[i] == false && d[i] <= min){
			min = d[i];
			minPos = i;
		}
	}
	return minPos;
}

int main() {
	//Reading in matrix from file
	fstream fin;
	fin.open("exGraph.txt");
	int num;
	int i = 0;
	int j = 0;

	fin >> num;
	int graphSize = num;
	int graph[graphSize][graphSize];


	while (fin >> num){
		graph[i][j] = num;
		j++;
		if (j >= graphSize){
			j = 0;
			i++;
		}
	}
	fin.close();


	//Input from user, start and end vertex
	int source;
	int dest;
	cout << "enter starting vertex: " << endl;
	cin >> source;
	if (cin.bad()) {
			cout << "Bad input. Exiting." << endl;
			return 0;
	}
	cout << "Source: " << source << endl;

	cout << "enter ending vertex: " << endl;
	cin >> dest;
	if (cin.bad()){
		cout << "Bad input. Exiting." << endl;
		return 0;
	}
	cout << "Dest: " << dest << endl;


	//Dijkstra's algorithm
	bool beenVisited[graphSize]; //vertex set Q
	int vLeftCt = graphSize;
	int dist[graphSize];
	int prev[graphSize];

	for (int i = 0; i < graphSize; i++){
		dist[i] = INT_MAX;
		prev[i] = NULL;
		beenVisited[i] = false; //add v to Q
	}
	dist[source] = 0;

	while(vLeftCt > 0){ //  while Q not empty
		int u = minDist(dist, beenVisited); //v w/ min dist & unvisited

		beenVisited[u] = true;
		vLeftCt--;
		if (u == dest){
			break;
		}

		for (int i = 0; i < graphSize; i++){ // unvisited neighbors of u
			if (beenVisited[i] == false && graph[u][i] != 0){
				int tempDist = dist[u] + graph[u][i];
				if (tempDist < dist[i]){
					dist[i] = tempDist;
					prev[i] = u;
				}
			}

		}
	} // end while()


	//Printing path
	int vertexPath[graphSize];
	for (int i = 0; i < graphSize; i++){
			vertexPath[i] = -1;
	}
	int v = dest;
	int vPathPos = 0;
	int stepCt = 0;
	while(prev[v] != source && dist[v] != INT_MAX){
		vertexPath[vPathPos] = prev[v];
		v = prev[v];
		vPathPos++;
		stepCt++;
	}

	int pathInOrder[stepCt-1];
	int pos = stepCt-1;
	for (int i = 0; i < stepCt; i++){
		pathInOrder[i] = vertexPath[pos];
		pos--;
	}

	cout << "Weight of path: " << dist[dest] << endl;
	cout << "Number of vertices: " << stepCt << endl;
	cout << "Path order (src to dest): ";
	for (int i = 0; i < stepCt; i++){
		cout << pathInOrder[i] << "  ";
	}

	return 0;
}
