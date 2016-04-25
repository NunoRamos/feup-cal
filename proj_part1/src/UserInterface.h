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

class Hotel{
	string name;
	unsigned long idNode;
	bool assigned;
public:
	Hotel(string name, int idNode);
	bool getAssigned();
	void setAssigned(bool flag);
	unsigned long getIdNode();
	friend class UserInterface;
};

class Van{


public:
	vector<Hotel*> hotelZone;
	Van(vector<Hotel*> hz);
};

class UserInterface{
	Graph *graph;
	priority_queue<Reservation *> reservations;
	vector<Node> destinations;
	int maxPassengers;
	vector<Hotel*> hotels;
	vector<Van*> vans;


public:
	UserInterface(Graph *g, int maxPassengers);
	bool addReservation (Reservation *r);
	void mainMenu();
	void transportPassengers();
	void goTo(unsigned long id);

	void reservationMenu();
	void readHotels();
	void printHotels();
	void printReservations();
	void readReservations();
	void gettingHotelsCloser();
};



#endif /* SRC_USERINTERFACE_H_ */
