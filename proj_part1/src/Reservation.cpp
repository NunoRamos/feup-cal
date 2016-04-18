#include "Reservation.h"

Reservation::Reservation(Node destination, string arrivalTime){
	this->destination = destination;
	this->arrivalTime = arrivalTime;
}

Node Reservation::getDestination(){
	return destination;
}

string Reservation::getArrivalTime(){
	return arrivalTime;
}
