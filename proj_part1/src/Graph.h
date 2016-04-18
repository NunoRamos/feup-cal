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
class Road;


class Road{
	long id;
	std::string name;
	bool twoWay;

public:
	Road(long id,std::string name,bool twoWay);
	long getID() const;
	std::string getName() const;
	bool isTwoWay() const;
	friend class Edge;
};

class Edge{
	Node *dest;
	Road *road;
	float weight;
public:
	Edge(Road *road);
	Road getRoad() const;
	friend class Node;
	void setDest(Node *dest);
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
	bool addEdge(Node *n);
	bool removeEdgeTo(Node *n);
};


class Graph{
	std::vector<Node> vertexSet;

};

#endif /* SRC_GRAPH_H_ */
