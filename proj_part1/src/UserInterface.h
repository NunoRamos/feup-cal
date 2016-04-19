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

class UserInterface{
	Graph *graph;
	priority_queue<Reservation *> reservations;
	vector<Node> destinations;
	int maxPassengers;


public:
	UserInterface(Graph g, int maxPassengers);
	bool addReservation (Reservation *r);
	void mainMenu();
	void transportPassengers();
};



#endif /* SRC_USERINTERFACE_H_ */
