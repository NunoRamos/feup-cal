/*
 * main.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#include <iostream>
#include "Graph.h"
#include "UserInterface.h"
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>



using namespace std;
/**
 * \brief function that reads the nodes from a file and stores them in a vector
 */
vector<Node *> readNodes(const char* filename) {

	vector<Node *> vec;
	ifstream file;
	stringstream ss;

	Coordinates *newCoord;
	Point *newPoint;
	Node *newNode;

	file.open(filename);
	if (file.is_open()) {

		unsigned long id;
		double lat, lon, x, y;
		string file_buf;
		file_buf.clear();

		while (!file.eof()) {
			if(getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> id;
				file_buf.clear();
				ss.clear();
			}


			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> lat;
				file_buf.clear();
				ss.clear();
			}

			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> lon;
				file_buf.clear();
				ss.clear();
			}

			if (getline(file, file_buf, ';')){
				ss<<file_buf;
				ss >> x;
				file_buf.clear();
				ss.clear();
			}

			if (getline(file, file_buf)){
				ss<<file_buf;
				ss >> y;
				file_buf.clear();
				ss.clear();
			}

			newCoord = new Coordinates(lon, lat);
		//	cout<<"x : "<<x;
			//cout<<"y : "<<y<<endl;
			newPoint = new Point(x, y);
			newNode = new Node(id, newCoord, newPoint);
			vec.push_back(newNode);

		}
	}

	file.close();

	return vec;
}

/**
 * vector that reads the Roads from a file and stores them in a vector
 */
vector<Road *> readRoads(const char* filename, vector<unsigned long> &ids) {

	vector<Road *> vec;
	ifstream file;

	file.open(filename);

	if (!file.is_open())
		return vec;

	while (!file.eof()) {

		string buff;
		buff.clear();
		stringstream ss;

		unsigned long id;
		string name;
		bool twoWay = false;

		if (getline(file, buff, ';')){
			ss << buff;
			ss >> id;
			ss.clear();
		}

		getline(file, name, ';');

		if (getline(file, buff)) {

			if(buff.c_str()[0] == 'F')
				twoWay = false;

			else twoWay = true;
		}

		Road *newRoad = new Road(id, name, twoWay);
		ids.push_back(id);
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
		vector<Road *> &roads, vector<unsigned long> roadIds) {

	ifstream file;
	file.open(filename);


	if (!file.is_open())
		return;

	while (!file.eof()) {

		string buff;
		buff.clear();
		stringstream ss;
		Road *currRoad = NULL;

		bool twoway;
		unsigned long edgeID, nodeFromID, nodeToID;
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

		bool foundMatch = false;

		for(unsigned int i = 0; i<roads.size(); i++){
			if (roads[i]->getID() == edgeID){
				twoway = roads[i]->isTwoWay();
				currRoad = roads[i];
				foundMatch = true;
			}
		}

		if(!foundMatch){
			cout<<"Search failure\n";
			cin.get();
			continue;
		}



		for(unsigned int i = 0; i<nodes.size(); i++){
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

		nodeFrom->addEdgeTo(nodeTo, new Edge(currRoad));

		if(twoway){
			nodeTo->addEdgeTo(nodeFrom, new Edge(currRoad));
		}
	}

	file.close();

}

int main(void) {

	vector<Node *> nodeVec;
	vector<Road *> roadVec;
	vector<unsigned long> roadIds;

	nodeVec = readNodes(NODES_FILENAME);
	roadVec = readRoads(ROADS_FILENAME, roadIds);

	readEdges(SUBRD_FILENAME, nodeVec, roadVec, roadIds);

	Graph *graph = new Graph(nodeVec);
	Node *source = graph->getNode(SOURCE_NODE_ID);

	if(source == NULL){
		cout << "Source node not found!\n";
		exit(30);
	}
	UserInterface *cli = new UserInterface(graph,MAX_PASSENGERS,source);


	cli->readHotels();
	cli->readReservations();
	//cli->mainMenu();




	return 0;
}

