/*
 * Graph.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#include "Graph.h"
using namespace std;

Edge::Edge(long id, string name,bool twoWay){
	this->id = id;
	this->name = name;
	this->twoWay = twoWay;
	this->dest = NULL;
}


string Edge::getName(){
	return name;
}

void Edge::setDest(Node *dest){
	this->dest = dest;
}

//******NODE************

/**
 *\brief Constructor for the Node class
 */
Node::Node(long id, Coordinates *coords, Point *point) {
	this->id = id;
	this->coords = coords;
	this->point = point;
	this->visited = false;
}

long Node::getId() {
	return id;
}

Coordinates Node::getCoordinates() {
	return *coords;
}

Point Node::getPoint() {
	return *point;
}

bool Node::wasVisited() {
	return visited;
}
