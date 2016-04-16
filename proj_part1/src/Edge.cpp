/*
 * Edge.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: epassos
 */

#include "Edge.h"

Edge::Edge(long id, string name, bool twoWay){
	this->id = id;
	this->name = name;
	this->twoWay = twoWay;
	this->nodeFrom = NULL;
	this->nodeTo = NULL;
}

Node Edge::getFrom(){
	return *nodeFrom;
}

Node Edge::getTo(){
	return *nodeTo;
}

bool Edge::isTwoWay(){
	return twoWay;
}

string Edge::getName(){
	return name;
}

