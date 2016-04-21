/*
 * Passenger.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "Reservation.h"
#include <string>

class Node;
using namespace std;

class Passenger{

	string name;
	unsigned int nif;

public:
	Passenger(string name, unsigned int nif, Node *destino, Reservation *reservation);
	string getName();
	unsigned int getNIF();
	Reservation* makeReservation(Node *destination, string arrivaltime);

};



#endif /* PASSENGER_H_ */
