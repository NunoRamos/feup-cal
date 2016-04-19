/*
 * Graph.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#include "Graph.h"
using namespace std;


//******ROAD************
Road::Road(long id, string name, bool twoWay){
	this->id = id;
	this->name = name;
	this->twoWay = twoWay;
}


string Road::getName() const{
	return name;
}

long Road::getID() const{
	return id;
}

bool Road::isTwoWay() const{
	return twoWay;
}

//******EDGE************
Edge::Edge(Road *road){
	this->road = road;
}

Road Edge::getRoad() const{
	return *road;
}

void Edge::setDest(Node *from, Node *to){
	this->dest = to;
	this->weight = getDistance(from->getCoordinates(), to->getCoordinates());
}

Node Edge::getDest() const{
	return *dest;
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

bool Node::addEdgeTo(Node *n, Edge *e){
	e->setDest(this,n);
	this->adj.push_back(e);
}

//********GRAPH************
Graph::Graph(vector<Node *> vertexSet){
	this->vertexSet = vertexSet;
}
