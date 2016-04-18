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

/**
 *\brief class that stores the information relative to an Edge
 *
 *	this info is not immediately useful for going through the graph
 */
class Road{
	long id;
	std::string name;
	bool twoWay;

public:

	/**
	 * \brief Basic Road class constructor
	 */
	Road(long id,std::string name,bool twoWay);

	/**
	 * \brief returns the ID of the Road
	 */
	long getID() const;

	/**
	 * \brief returns the name of a Road
	 */
	std::string getName() const;

	/**
	 *\brief returns true if the Edges relative to this road can be travelled in any direction
	 */
	bool isTwoWay() const;
	friend class Edge;
};

/**
 *\brief class that connects the Nodes of the Graph
 */
class Edge{
	Node *dest; ///< destination of the Edge
	Road *road; ///< Road that stores the information relative to this Edge (name, ID, etc...)
	float weight; ///< "length" of the road, used in calculating fastest path to a Node
public:
	/**
	 *\brief Basic class constructor
	 */
	Edge(Road *road);

	/**
	 * \brief returns the Road that stores the information relative to this Edge
	 */
	Road getRoad() const;

	/**
	 * \brief sets the destination Node, calls the getDistance function of Coordinates.h to set the weight of the Edge
	 */
	void setDest(Node *from,Node *to);

	/**
	 * \brief Returns the destination Node
	 */
	Node getDest() const;

	friend class Node;
};


/**
 * \brief class that refers to certain points on a map that are reachable through Edges
 */
class Node{
	long id; ///< Node ID
	Coordinates* coords; ///< Coordinate position of the Node
	Point* point;	///< Coordinate position in radians
	bool visited; ///< boolean that is set to true when a Node has been reached
	public :std::vector<Edge *> adj; ///< Edges that go from this Node to another Node

public:
	/**
	 * \brief Basic class constructor
	 */
	Node(long id, Coordinates *coords, Point *point);

	/**
	 * \brief returns the ID of the Node
	 */
	long getId();

	/**
	 * \brief returns the Coordinates of the Node
	 */
	Coordinates getCoordinates();

	/**
	 * \brief returns the Coordinates of the Node as a Point (x and y are the coordinates in radians)
	 */
	Point getPoint();

	/**
	 * \brief checks the visited attribute to determine if a Node has already been travelled through
	 */
	bool wasVisited();

	/**
	 * \brief adds an Edge to another Node
	 *
	 *  calls the setDest function of the Edge class
	 *
	 * \return true if the Edge has been sucessfully added
	 */
	bool addEdgeTo(Node *n, Edge *e);

	/**
	 * TODO
	 */
	bool removeEdgeTo(Node *n);
};

/**
 * \brief class that holds a set of Nodes connected by Edges
 */
class Graph{
	std::vector<Node> vertexSet;
};

#endif /* SRC_GRAPH_H_ */
