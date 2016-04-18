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

using namespace std;

class Reservation{

	Node *destination;
	string arrivalTime;

public:
	Reservation(Node *destination, string arrivalTime);
	Node *getDestination();
	string getArrivalTime();
};



#endif /* RESERVATION_H_ */
