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

#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#define HOTELS_FILENAME "hotels.txt"

UserInterface::UserInterface(Graph *g, int maxPassengers){
	this->graph = g;
	this->maxPassengers = maxPassengers;
}

Hotel::Hotel(string name, int idNode)
{
	this->name = name;
	this->idNode = idNode;
}

void UserInterface::readHotels()
{
	ifstream file;
	file.open(HOTELS_FILENAME);


	if (!file.is_open())
		return;

	while (!file.eof()) {

		string buff;
		buff.clear();
		stringstream ss;

		string name;
		unsigned long  idNode;


		if (getline(file, buff, ';')){
			ss << buff;
			ss >> idNode;
			ss.clear();
		}

		if(!getline(file, name, ';'))
		{
			break;
		}

		Hotel* h = new Hotel(name, idNode);
		hotels.push_back(h);

	}
}

void UserInterface::printHotels()
{
	cout << endl;
	for(unsigned int i = 0; i < hotels.size(); i++)
	{
		cout << i+1 << " - " << hotels[i]->name << endl;
	}
}

void UserInterface::printReservations()
{
	priority_queue<Reservation * > temp;

	cout<<"Reservations: "<<endl<<endl;
	while(!reservations.empty()){
		cout<<"Name: ";
		cout<<reservations.top()->getClient()->getName()<<endl;
		cout<<"Destination: ";
		cout<<reservations.top()->getDestination()->getId()<<endl;
		cout<<"Arrival Time: ";
		cout<<reservations.top()->getArrivalTime()<<endl<<endl;

		temp.push(reservations.top());
		reservations.pop();
	}

	while(!temp.empty()){
		reservations.push(temp.top());
		temp.pop();
	}

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

void UserInterface::reservationMenu() {
	string name;
	int nif;
	int hotel;
	string arrival_time;

	cout<<"Reservation Menu\n";

	cout<<"Insert name: ";
	getline(cin, name);

	cout<<"Insert NIF: ";
	cin >> nif;
	cin.ignore(1000, '\n');

	printHotels();
	cout << "Choose Destination: ";
	cin >> hotel;
	cin.ignore(1000, '\n');
	while(hotel<1 || hotel>hotels.size()){
		cout<<"Please choose a valid hotel: ";
		cin >> hotel;
		cin.ignore(1000, '\n');
	}

	cout<<"Insert Arrival Time: ";
	cin >> arrival_time;
	cin.ignore(1000, '\n');

	Passenger* p = new Passenger(name, nif);

	Reservation* res = new Reservation(graph->getNode(hotels[hotel-1]->idNode), arrival_time, p);

	addReservation(res);
}

void UserInterface::mainMenu() {
	cout<<"Welcome!\n";
	cout<<"Please choose an option: \n";
	cout<<"1 - Client Interface\n";
	cout<<"2 - Make transfer\n";
	cout<<"3 - Exit\n";
	cout<<"\nYour option: ";

	readHotels();

	int op;
	cin>>op;
	cin.ignore(1000, '\n');

	while(op<1 || op>3)
		cout<<"Please choose a valid option: ";

	switch(op){
	case 1:
		reservationMenu();
		mainMenu();
		//TODO client screen - schedule transfers, add clients, etc...
		break;
	case 2:
		//TODO plan the trip for the clients who arrive first
		printReservations();
		mainMenu();
		break;
	case 3:
		exit(0);
	}
	cin.get();
}

void UserInterface::goTo(unsigned long id_dest){

	unsigned long id_origin = 3713666414; //3713666414 -> 25532201
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


