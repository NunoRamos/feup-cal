/*
 * UserInterface.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: epassos
 */

#include "UserInterface.h"
#include "Reservation.h"
#include "Passenger.h"

UserInterface::UserInterface(Graph *g, int maxPassengers){
	this->graph = graph;
	this->maxPassengers = maxPassengers;
}

bool UserInterface::addReservation(Reservation *r){

	priority_queue<Reservation * > temp;

	string name = r->getClient()->getName();
	while(!reservations.empty()){
		string topName = reservations.top()->getClient()->getName();
		if(topName == name){
			return false;
		}

		temp.push(reservations.top());
		reservations.pop();
	}

	while(!temp.empty()){
		reservations.push(temp.top());
		temp.pop();
	}
	reservations.push(r);
	return true;
}

void UserInterface::mainMenu() const{
	cout<<"Welcome!\n";
	cin.get();
}


