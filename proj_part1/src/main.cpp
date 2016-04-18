/*
 * main.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#include <iostream>
#include "Graph.h"
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

/**
 * \brief function that reads the nodes from a file and stores them in a vector
 */
vector<Node *> readNodes(const char* filename) {

	vector<Node *> vec;
	ifstream file;
	stringstream ss;

	file.open(filename);
	if (file.is_open()) {

		long id;
		double lat, lon, x, y;
		string file_buf;

		while (!file.eof()) {
			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> id;
				ss.clear();
			}

			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> lat;
				ss.clear();
			}

			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> lon;
				ss.clear();
			}

			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> x;
				ss.clear();
			}

			if (getline(file, file_buf)){
				ss<<file_buf;
				ss >> y;
				ss.clear();
			}

			Coordinates *newCoord = new Coordinates(lon, lat);
			Point *newPoint = new Point(x, y);
			Node *newNode = new Node(id, newCoord, newPoint);

			vec.push_back(newNode);
		}
	}

	file.close();

	return vec;
}

/**
 * vector that reads the Roads from a file and stores them in a vector
 */
vector<Road *> readRoads(const char* filename) {

	vector<Road *> vec;
	ifstream file;

	file.open(filename);

	if (!file.is_open())
		return vec;

	while (!file.eof()) {

		string buff;
		stringstream ss;

		long id;
		string name;
		bool twoWay;

		if (getline(file, buff, ';')){
			ss << buff;
			ss >> id;
			ss.clear();
		}

		getline(file, name, ';');

		if (getline(file, buff)) {
			twoWay = (buff == "False") ? false : true;
		}

		Road *newRoad = new Road(id, name, twoWay);
		vec.push_back(newRoad);
	}

	file.close();

	return vec;
}

/**
 * \brief function that reads the edges from the subroads file and creates the aproppriate edges in the nodes
 *
 * the function creates an Edge, sets the Road it refers to and checks if it is two way and
 * calls the addEdge function in the Node(s)
 *
 * TODO end
 */
void readEdges(const char *filename, vector<Node *> &nodes,
		vector<Road *> &roads) {

	ifstream file;
	file.open(filename);

	if (!file.is_open())
		return;

	while (!file.eof()) {

		string buff;
		stringstream ss;
		Edge *newEdge = NULL;

		bool twoway;
		long edgeID, nodeFromID, nodeToID;
		Node *nodeFrom, *nodeTo;

		if (getline(file, buff, ';')){
			ss << buff;
			ss >> edgeID;
			ss.clear();
		}

		if (getline(file, buff, ';')){
			ss << buff;
			ss >> nodeFromID;
			ss.clear();
		}

		if (getline(file, buff)){
			ss << buff;
			ss >> nodeToID;
			ss.clear();
		}

		for(int i = 0; i<roads.size(); i++){
			if (roads[i]->getID() == edgeID){
				twoway = roads[i]->isTwoWay();
				newEdge = new Edge(roads[i]);
			}
		}

		for(int i = 0; i<nodes.size(); i++){
			if(nodes[i]->getId() == nodeFromID)
				nodeFrom = nodes[i];

			if(nodes[i]->getId() == nodeToID)
				nodeTo = nodes[i];
		}

		if(nodeFrom == NULL){
			cout << "nodeFrom from not found\n";
			continue;
		}

		if(nodeTo == NULL){
			cout << "nodeTo not found\n";
			continue;
		}

		nodeFrom->addEdgeTo(nodeTo, newEdge);

		if(twoway){
			nodeTo->addEdgeTo(nodeFrom, newEdge);
		}


	}

}

int main(void) {

	vector<Node *> nodeVec;
	vector<Road *> roadVec;

	nodeVec = readNodes("nodes.txt");
	roadVec = readRoads("roads.txt");

	readEdges("subroads.txt", nodeVec, roadVec);

	/*for(unsigned int i = 0; i< EdgeVec.size(); i++){ FIXME remove
	 if(EdgeVec[i]->getName() != "")
	 cout<<EdgeVec[i]->getName()<<endl;
	 }*/
	return 0;
}

