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

using namespace std;

vector<Node *> readNodes(const char* filename){


	vector<Node *> vec;
	ifstream file;


	file.open(filename);
	if(file.is_open()){

		long id;
		float lat, lon, x, y;
		string file_buf;

		while(!file.eof()){
			if(getline(file,file_buf,';'))
				id = strtol(file_buf.c_str(),NULL,10);

			if(getline(file,file_buf,';'))
				lat = strtof(file_buf.c_str(),NULL);

			if(getline(file,file_buf,';'))
				lon = strtof(file_buf.c_str(),NULL);

			if(getline(file,file_buf,';'))
				x = strtof(file_buf.c_str(),NULL);

			if(getline(file,file_buf))
				y = strtof(file_buf.c_str(),NULL);

			Coordinates *newCoord = new Coordinates(lon,lat);
			Point *newPoint = new Point(x,y);
			Node *newNode = new Node(id,newCoord,newPoint);

			vec.push_back(newNode);
		}
	}

	file.close();

	return vec;
}

vector<Edge *> readRoads(const char* filename){

	vector<Edge *> vec;
	ifstream file;

	file.open(filename);

	if(!file.is_open())
		return vec;

	while(!file.eof()){

		string buff;

		long id;
		string name;
		bool twoWay;

		if(getline(file,buff,';'))
			id = strtol(buff.c_str(), NULL, 10);

		getline(file,name,';');

		if(getline(file,buff)){
			twoWay = (buff == "False")? false : true;
		}

		Edge *newEdge = new Edge(id,name,twoWay);
		vec.push_back(newEdge);
	}


	return vec;
}

int main (void){

	vector<Node *> NodeVec;
	vector<Edge *> EdgeVec;

	NodeVec = readNodes ("nodes.txt");
	EdgeVec = readRoads ("roads.txt");

	for(unsigned int i = 0; i< EdgeVec.size(); i++){
		if(EdgeVec[i]->getName() != "")
		cout<<EdgeVec[i]->getName()<<endl;
	}
	return 0;
}



