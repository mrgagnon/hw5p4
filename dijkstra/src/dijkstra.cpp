/* Maylee Gagnon
 * CS 2223 HW5P4
 * 11.26.2019
 */
#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;

int numV;

/* TODO Get weight between two vertexes
 *
 */
int w(int a, int b){
	// Needs access to matrix
	// Matrix[a][b] = weight
	return 1;
}

/* Weight graph,
 * @param G Weighted graph
 * @param s Starting vertex
 * @param e Ending vertex
 * @return The length of the shortest path between s and e.
 */
int dijkstra(int g[][10], int s) {
	int dist[numV];
	int prevV[numV];
	int pQueue[numV];

	for (int i = 0; i < numV; i++){
		dist[i] = INT_MAX;
		prevV[i] = NULL;
		//TODO insert vertex into priority queue
	}
	dist[s] = 0;
	//TODO Decrease / update priority of s with ds
	//TODO Vt = null

	for (int i = 0; i < numV; i++){
		int ustar;// TODO = deleteMin(Q)
		//TODO vt = vt U u

		for (int u = 0; u < 10; u++){ //TODO vertex u adjacent to u*
			if (dist[ustar] + w(ustar,u) < dist[u]){
				dist[u] = dist[ustar] + w(ustar,u);
				prevV[u] = ustar;
				// TODO Decrease(Q,u,dist[u])
			}
		}
	}
	return 0;
}

int main() {
	cout << "Hi" << endl;

	fstream fin;
	fin.open("exGraph.txt");
	int num;
	int i = 0;
	int j = 0;

	fin >> num;
	int numV = num;
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

	int start;
	cout << "enter starting vertex: " << endl;
	cin >> start;
	if (cin.bad()) {
			cout << "Bad input. Exiting." << endl;
			return 0;
	}

	int end;
	cout << "enter ending vertex: " << endl;
	cin >> end;
	if (cin.bad()){
		cout << "Bad input. Exiting." << endl;
		return 0;
	}

	//TODO Call to dijkstra()
	//TODO Output


	/*
	for (int i = 0; i < graphSize; i++){
		for (int j = 0; j < graphSize; j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}
