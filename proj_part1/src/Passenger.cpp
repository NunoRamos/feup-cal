#include "Passenger.h"

using namespace std;

Passenger::Passenger(string name, unsigned int nif, Node *destino, Reservation *reservation){
	this->name = name;
	this->nif = nif;
}

string Passenger::getName(){
	return name;
}

unsigned int Passenger::getNIF(){
	return nif;
}
