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

	cout << "dist: ";
	for (int i = 0; i < graphSize; i++){
		cout << i << ":" << dist[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < graphSize; i++){
		cout << prev[i] << ", ";
	}

	/*
	bool beenVisited[graphSize];
	int dist[graphSize];
	//int unvistedSet[graphSize];
	for (int i = 0; i < graphSize; i++){
		beenVisited[i] = false; // mark all nodes unvisited
		dist[i] = INT_MAX; //set all distances to infinity
	}

	dist[s] = 0; //Initial node, distance zero
	int curNode = s;
	bool cont = true;

	while (cont){
		int smallestTempDist = INT_MAX;
		int smallestTempDistPos;
		for (int i = 0; i < graphSize -1; i++){ // check nodes for unvisited neighbors
			if (graph[curNode][i] != 0 && beenVisited[i] == false){
				int tempDist = dist[curNode] + graph[curNode][i]; // tentative distance through current node
				if (tempDist < dist[i]){ // new distance is less than old distance than set new value
					dist[i] = tempDist;
				}
				if (tempDist < smallestTempDist){
					smallestTempDist = tempDist;
					smallestTempDistPos = i;
				}
			}
		}
		beenVisited[curNode] = true;
		if (beenVisited[dest] == true){
			break;
		}
		else {
			curNode = smallestTempDistPos;
		}
	}

	 */

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
