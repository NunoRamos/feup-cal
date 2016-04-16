/*
 * Node.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

using namespace std;

#include "Coordinates.h"
#include <iostream>

class Node{

	long id;
	Coordinates* coords;
	Point* point;
	bool destination;
	string name;

public:
	Node(long id, Coordinates *coords, Point *point, bool destination, string name);
	long getId();
	Coordinates getCoordinates();
	Point getPoint();
	bool isDestination();
	string getName();
};

#endif /* SRC_NODE_H_ */
