/*
 * main.h
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#include <iostream>
#include <vector>
#include "Coordinates.h"

class Node;
class Edge;
class Graph;

struct NodePair{
	Node *n1;
	Node *n2;
};

class Edge{
	long id;
	std::vector<struct NodePair *> pairs;
	std::string name;
	bool twoWay;

public:
	Edge(long id,std::string name,bool twoWay);
	void setDest(Node *dest);
	std::string getName();
	friend class Node;
	friend class Graph;
};

class Node{
	long id;
	Coordinates* coords;
	Point* point;
	bool visited;
	std::vector<Edge> adj;

public:
	Node(long id, Coordinates *coords, Point *point);
	long getId();
	Coordinates getCoordinates();
	Point getPoint();
	bool wasVisited();
	bool addEdge(Edge *e, Node *n);
	bool removeEdgeTo(Node *n);
};


class Graph{
	std::vector<Node> vertexSet;

};

#endif /* SRC_GRAPH_H_ */
