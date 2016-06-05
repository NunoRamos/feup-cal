/*
 * Reservation.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_
#include <string>
#include <sstream>

class Passenger;
class Node;
using namespace std;

class Reservation {

	Node *destination;
	string arrivalTime;
	Passenger *client;

public:
	Reservation();
	Reservation(Node *destination, string arrivalTime, Passenger *client);
	Node *getDestination() const;
	string getArrivalTime() const;
	Passenger *getClient() const;

	bool operator <(const Reservation &res) const;
	void operator= (const Reservation &res);

};

#endif /* RESERVATION_H_ */
