/* Maylee Gagnon
 * CS 2223 HW5P4
 * 11.26.2019
 */
#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;

/* Vertex left in Q/not visited yet with the minimum distance
 *
 */
int minDist(int d[10], bool visited[10]){
	int min = INT_MAX;
	int minPos = 0;

	for (int i = 0; i < 10; i++){
		if (visited[i] == false && d[i] <= min){
			min = d[i];
			minPos = i;
		}
	}
	return minPos;
}

int main() {
	cout << "Hi" << endl;

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

	int source = 0;
	int dest = 9;

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

	/*
	cout << "dist from A/0: ";
	for (int i = 0; i < graphSize; i++){
		cout << dist[i] << ", ";
	}
	cout << endl;

	cout << "prev from A/0: ";
	for (int i = 0; i < graphSize; i++){
		cout << prev[i] << ", ";
	}
	cout << endl;
	*/

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
	cout << "path:";
	for (int i = 0; i < stepCt; i++){
		cout << vertexPath[i] << ", ";
	}

	/*
	int start;
	cout << "enter starting vertex: " << endl;
	cin >> start;
	if (cin.bad()) {
		cout << "Bad input. Exiting." << endl;
		return 0;
	}
	cout << start<< endl ;

	int end;
	cout << "enter ending vertex: " << endl;
	cin >> end;
	if (cin.bad()){
		cout << "Bad input. Exiting." << endl;
		return 0;
	}
	cout << end;
	 */
	return 0;
}
