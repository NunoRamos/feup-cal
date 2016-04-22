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
#include <climits>
#include <queue>
#include <list>

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
	Node* getDest() const;

	friend class Node;
	friend class Graph;
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
	int indegree; ///<Number of edges enter on the node
	bool processing; ///<If the node is being processed
	double dist; ///<Distance to the source node
	Node* path; ///<Node closer to this node on is way to the source node

public:

	friend class Graph;

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

	/**
	 * \brief returns the indegree of the node
	 */
	int getIndegree();

};

/**
 * \brief class that holds a set of Nodes connected by Edges
 */
class Graph{

public:
	std::vector<Node *> vertexSet;
	/**
	 * \brief Basic class constructor
	 */
	Graph(std::vector<Node *> vertexSet);

	/**
	 * \brief adds an already created Node to a graph
	 *
	 * \ret returns true if sucessful
	 */
	bool addNode(Node *n);

	/**
	 * \brief adds a new Node to a graph
	 *
	 * \ret returns true if sucessful
	 */
	bool addNode(long id,double lat,double lon,double x,double y);

	/**
	 * \brief removes a Node from a graph, to be searched by its latitude and longitude
	 *
	 * \ret true if sucessful
	 */
	bool removeNode(double lat, double lon);


	/**
	 * \brief adds an already created Edge to a Graph
	 *
	 * \ret true if sucessful
	 */
	bool addEdge(Edge *e);

	/**
	 * \brief adds a new Edge to a Graph
	 *
	 * \ret true if sucessful
	 */
	bool addEdge(Node *nodeFrom, Node *nodeTo, Road *info);

	/**
	 * \brief removes an edge from a Graph, to be searched by its ID
	 */
	bool removeEdge(long id);

	/**
	 * \brief Resets all the indegrees, and then recalculates their value
	 */
	void resetIndegrees();

	/**
	 * \brief Uses  Bellman Ford's algorithm to determine the shortest path to any node from a source node
	 */
	void bellmanFordShortestPath(long source);

	/**
	 * \brief Uses Dijkstra's algorithm to determine the shortest path to any node from a source node
	 */
	void dijkstraShortestPath(long source);

	/**
	 * \brief Get path from origin to dest
	 */
	std::vector<Node*> getPath(long origin, long dest);

	/**
	 * \brief Gets the node that has the id, id
	 */
	Node* getNode(long id);
};

#endif /* SRC_GRAPH_H_ */
