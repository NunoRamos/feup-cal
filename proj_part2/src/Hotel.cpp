/*
 * Hotel.cpp
 *
 *  Created on: May 30, 2016
 *      Author: epassos
 */

#include "Hotel.h"

Hotel::Hotel(string name, Node *n) {
	this->name = name;
	this->node = n;
	this->assigned = false;
}

bool Hotel::getAssigned() {
	return this->assigned;
}

void Hotel::setAssigned(bool flag) {
	this->assigned = flag;
}

string Hotel::getName() const {
	return name;
}

Node *Hotel::getNode() const {
	return node;
}

