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

class Passenger {

	string name;
	unsigned int nif;

public:
	/**
	 * \brief basic class constructor
	 *
	 * \arg name Name of the client
	 * \arg nif NIF of the client
	 */
	Passenger(string name, unsigned int nif);

	/**
	 * \brief returns the name of the client
	 */
	string getName();

	/**
	 * \brief returns the NIF of the client
	 */
	unsigned int getNIF();

	/**
	 * \brief creates a reservation for the client
	 *
	 * \arg destination Node to where the client will be transfered
	 * \arg arrivaltime Time of the client's arrival, should be formatted in hhmm (e.g. 1245 for 12h 45m)
	 */
	Reservation* makeReservation(Node *destination, string arrivaltime);

};

#endif /* PASSENGER_H_ */
