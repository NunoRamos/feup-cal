#include "Reservation.h"

Reservation::Reservation(Node *destination, string arrivalTime, Passenger *client){
	this->destination = destination;
	this->arrivalTime = arrivalTime;
	this->client = client;
}

Node *Reservation::getDestination() const{
	return destination;
}

string Reservation::getArrivalTime() const{
	return arrivalTime;
}

Passenger* Reservation::getClient() const{
	return client;
}


bool Reservation::operator <(const Reservation &res1) const
{
	stringstream ss;
	int r1, r2;

	ss << arrivalTime;
	ss >> r1;

	ss.clear();

	ss << res1.getArrivalTime();
	ss >> r2;

	if(r1 > r2)
		return true;
	else
		return false;
}


