/* Maylee Gagnon
 * CS 2223 HW5P4
 * 11.26.2019
 */
#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;


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

	int s = 0;
	int dest = 9;

	while (fin >> num){
		graph[i][j] = num;
		j++;
		if (j >= graphSize){
			j = 0;
			i++;
		}
	}
	fin.close();


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


	for (int i = 0; i < graphSize; i++){
		cout << dist[i] << ", ";
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
