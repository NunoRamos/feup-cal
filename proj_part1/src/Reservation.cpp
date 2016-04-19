#include "Reservation.h"

Reservation::Reservation(Node *destination, string arrivalTime, Passenger *client){
	this->destination = destination;
	this->arrivalTime = arrivalTime;
}

Node *Reservation::getDestination(){
	return destination;
}

string Reservation::getArrivalTime(){
	return arrivalTime;
}

Passenger* Reservation::getClient(){
	return client;
}

