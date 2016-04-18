#include "Passenger.h"

using namespace std;

Passenger::Passenger(string name, unsigned int nif, Node destino, Reservation reservation){
	this->name = name;
	this->nif = nif;
	this->destino = destino;
	this->reservation = reservation;
}

string Passenger::getName(){
	return name;
}

unsigned int Passenger::getNif(){
	return nif;
}

Node Passenger::getDestino(){
	return destino;
}

Reservation Passenger::getReservation(){
	return reservation;
}
