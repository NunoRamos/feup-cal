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

class Hotel
{
	string name;
	unsigned long idNode;
public:
	Hotel(string name, int idNode);
	friend class UserInterface;
};

class UserInterface{
	Graph *graph;
	priority_queue<Reservation> reservations;
	vector<Node> destinations;
	int maxPassengers;
	vector<Hotel*> hotels;


public:
	UserInterface(Graph *g, int maxPassengers);
	bool addReservation (Reservation r);
	void mainMenu();
	void transportPassengers();
	void goTo(unsigned long id);

	void reservationMenu();
	void readHotels();
	void printHotels();
	void printReservations();
	void readReservations();

	void aux();
};



#endif /* SRC_USERINTERFACE_H_ */
