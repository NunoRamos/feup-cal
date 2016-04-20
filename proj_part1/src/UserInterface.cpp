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
	this->graph = g;
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

void UserInterface::goTo(long id_dest){
	cout<<"Entrei na funcao goTo\n";

	long id_origin = 25503940;
	vector<Node * > path;


	graph->resetIndegrees();
	cout<<"Sai da funcao indegree\n";
	graph->bellmanFordShortestPath(id_dest);

	path = graph->getPath(id_origin, id_dest);

/*	for(unsigned int i=0; i<path.size(); i++){
		cout<<"id "<<i<<" "<<path[i]->getId()<<endl;
	}*/
}


