/*
 * Passenger.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

using namespace std;

class Passenger{

	string name;
	unsigned int nif;
	Node destino;
	Reservation reservation;

public:
	Passenger(string name, unsigned int nif, Node destino, Reservation reservation);
	string getName();
	unsigned int getNif();
	Node getDestino();
	Reservation getReservation();

};



#endif /* PASSENGER_H_ */
