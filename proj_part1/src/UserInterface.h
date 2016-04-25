/*
 * UserInterface.h
 *
 *  Created on: Apr 19, 2016
 *      Author: epassos
 */

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

#include "Graph.h"
#include "Passenger.h"
#include "Reservation.h"
#include <queue>

#define NODES_FILENAME "test_nodes.txt"
#define ROADS_FILENAME "test_roads.txt"
#define SUBRD_FILENAME "test_subroads.txt"

//airport node
#define SOURCE_NODE_ID 112640154
#define MAX_PASSENGERS 10


class Hotel
{
	string name;
	Node *node;
public:
	/**
	 * \brief class constructor
	 *
	 * \arg name Name of the Hotel
	 * \arg n Node that refers to the position of the Hotel
	 */
	Hotel(string name, Node *n);
	friend class UserInterface;
};

class UserInterface{
	Graph *graph;
	priority_queue<Reservation> reservations;
	vector<Node> destinations;
	int maxPassengers;
	vector<Hotel*> hotels;
	Node *source;

public:

	/**
	 * \brief class constructor
	 *
	 * \arg g Graph that will be used by the program
	 * \arg maxPassengers maximum number of passengers in one trip
	 * \arg source Node from which the trips are planned, in this case it represents the airport
	 */
	UserInterface(Graph *g, int maxPassengers, Node *source);

	/**
	 * \brief Adds a Reservation to the priority queue
	 */
	bool addReservation (Reservation r);

	/**
	 * \brief Displays the main menu of the program
	 */
	void mainMenu();

	/**
	 * \brief Plans the transfer
	 */
	void transportPassengers();

	/**
	 * \brief gets the path to the node with the ID id_dest from the node with the ID id_from
	 */
	void transferTo(unsigned long id_from, unsigned long id_dest);

	/**
	 * \brief displays the menu of the reservations
	 */
	void reservationMenu();

	/**
	 * \brief reads the Hotels from a file and puts them in the hotels vector
	 */
	void readHotels();

	/**
	 * \brief displays all the hotels
	 */
	void printHotels();

	/**
	 * \brief displays all the reservations
	 */
	void printReservations();

	/**
	 * \brief reads all the reservations from a file and puts them in a priority queue which has the next reservation in the top
	 */
	void readReservations();


	/**
	 * \brief displays the passengers that will be transfered and the path that will be taken
	 */
	void transferMenu();
};



#endif /* SRC_USERINTERFACE_H_ */
