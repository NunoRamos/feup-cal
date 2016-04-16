/*
 * Edge.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

#include "Node.h"
#include <iostream>

using namespace std;


class Edge{

	long id;
	Node* nodeFrom, *nodeTo;
	bool twoWay;
	string name;

public:
	Edge(long id, string name, bool twoWay);
	Node getFrom();
	Node getTo();
	bool isTwoWay();
	string getName();
};


#endif /* SRC_EDGE_H_ */
