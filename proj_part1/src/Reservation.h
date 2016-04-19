/*
 * Reservation.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_
#include <string>
#include "Graph.h"

class Passenger;
using namespace std;

class Reservation{

	Node *destination;
	string arrivalTime;
	Passenger *client;

public:
	Reservation(Node *destination, string arrivalTime);
	Node *getDestination();
	string getArrivalTime();
	Passenger *getClient();
	void setClient();
};



#endif /* RESERVATION_H_ */
