/*
 * UserInterface.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: epassos
 */

#include "UserInterface.h"
#include "Reservation.h"
#include "Passenger.h"
#include <cstdlib>

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
	cout<<"Please choose an option: \n";
	cout<<"1 - Client Interface\n";
	cout<<"2 - Make transfer\n";
	cout<<"3 - Exit\n";
	cout<<"\nYour option: ";

	int op;
	cin>>op;

	while(op<1 || op>3)
		cout<<"Please choose a valid option: ";

	switch(op){
	case 1:
		//TODO client screen - schedule transfers, add clients, etc...
		break;
	case 2:
		//TODO plan the trip for the clients who arrive first
		break;
	case 3:
		exit(0);
	}
	cin.get();
}

void UserInterface::goTo(long id_dest){

	long id_origin = 3713666414; //3713666414 -> 25532201
	vector<Node * > path;


	graph->resetIndegrees();
	//graph->bellmanFordShortestPath(id_dest);
	cout<<"Dijkstra\n"; cin.get();//TODO remove
	graph->dijkstraShortestPath(id_origin);
	cout<<"Dijkstra over\n";cin.get();

	path = graph->getPath(id_origin, id_dest);

	for(unsigned int i=0; i<path.size(); i++){
		cout<<"id "<<i<<" "<<path[i]->getId()<<endl;
	}
}


