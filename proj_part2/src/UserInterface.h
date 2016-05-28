/*
 * UserInterface.h
 *
 *  Created on: Apr 19, 2016
 *      Author: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

#include "Graph.h"
#include "Passenger.h"
#include "Reservation.h"
#include "graphviewer.h"
#include <queue>

#define NODES_FILENAME "test_nodes.txt"
#define ROADS_FILENAME "test_roads.txt"
#define SUBRD_FILENAME "test_subroads.txt"

//////////////////////////
/////PART 2 files
#define NAMES_DICTIONARY "names_dictionary.txt"
#define ROAD_DICTIONARY "roads_dictionary.txt"

//airport node
#define SOURCE_NODE_ID 112640154
#define MAX_PASSENGERS 10

class Hotel {
	string name;
	Node *node;
	bool assigned;
public:
	/**
	 * \brief class constructor
	 *
	 * \arg name Name of the Hotel
	 * \arg n Node that refers to the position of the Hotel
	 */
	Hotel(string name, Node *n);

	/**
	 * \brief checks if the hotel is already assigned to a van
	 */
	bool getAssigned();

	/**
	 * \brief sets the assigned flag to represent the current state of the hotel
	 */
	void setAssigned(bool flag);

	/**
	 * \brief returns the name of the hotel
	 */
	string getName() const;

	/**
	 * \brief returns the node where the hotel is located
	 */
	Node *getNode() const;
	friend class UserInterface;
};

class Van {
	vector<Hotel> hotelZone;
	vector<Reservation> passengers;

public:
	/**
	 * \brief basic class constructor
	 *
	 * \arg hz vector of hotels to which this van will transfer clients
	 */
	Van(vector<Hotel> hz);

	//PART 2
	/**
	 * \brief returns the hotels served by the
	 */
	vector<Hotel> getHotels() const;
	friend class UserInterface;
};

class UserInterface {
	Graph *graph;
	priority_queue<Reservation> reservations;
	vector<Node> destinations;
	int maxPassengers;
	vector<Hotel> hotels;
	Node *source;
	vector<Van*> vans;

	double maxLat, minLat, maxLng, minLng;


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
	bool addReservation(Reservation r);

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
	vector<Node *> transferTo(unsigned long id_from, unsigned long id_dest);

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

	void updateCoordinates();

	void displayGraph(vector<Node *> path);

	/**
	 * \brief sets a vector of hotels to be served by each van
	 *
	 * Each van has an equal number of hotels to service, these are, for each van, the first unassigned hotel and the ones closest to it
	 * the size of the vector depends on the number of available vans
	 */
	void assignHotelsToVans();

	/**
	 * \brief sets a vector of reservations to be satisfied by each van
	 *
	 * each van has a number < MAX_PASSENGERS of clients to transfer to an hotel that belongs to their zone vector
	 */
	void assignClientsToVans();


	/////////////////////////////////////////////////////////
	//PART2
	/////////////////////////////////////////////////////////

	/**
	 * \brief prompts the user for the name of a road and searches the vans (using exact and, if it fails, approximate string matching
	 * to get a list of Vans that pass that road
	 */
	void searchVanByRoad();

	/**
	 * \brief prompts the user for the name of a client and searches the vans (using exact and, if it fails, approximate string matching
	 * to get a list of Vans that transport clients with that name.
	 */
	void searchVanByClient();


};

#endif /* SRC_USERINTERFACE_H_ */
