/*
 * Node.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: epassos
 */

#include "Node.h"

/**
 *\brief Constructor for the Node class
 */
Node::Node(long id, Coordinates *coords, Point *point, bool destination, string name){
	this->id = id;
	this->coords = coords;
	this->point = point;
	this->destination = destination;
	this->name = name;
}

long Node::getId(){
	return id;
}

Coordinates Node::getCoordinates(){
	return *coords;
}

Point Node::getPoint(){
	return *point;
}

bool Node::isDestination(){
	return destination;
}

string Node::getName(){
	return name;
}

