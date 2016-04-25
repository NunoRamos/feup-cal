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
#define RESERVATIONS_FILENAME "reservations.txt"

UserInterface::UserInterface(Graph *g, int maxPassengers, Node *source){
	this->graph = g;
	this->maxPassengers = maxPassengers;
	this->source = source;
}

Hotel::Hotel(string name, Node *n)
{
	this->name = name;
	this->node = n;
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

		Node *n = graph->getNode(idNode);

		if(n == NULL){
			cout << "Node not found: " << idNode << endl;
			continue;
		}

		Hotel* h = new Hotel(name, n);
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

void UserInterface::readReservations()
{
	ifstream file;
	file.open(RESERVATIONS_FILENAME);


	if (!file.is_open())
		return;

	while (!file.eof()) {

		string buff;
		buff.clear();
		stringstream ss;

		string name;
		int nif;
		unsigned int hotel;
		string arrival_time;

		getline(file, name, ';');


		if (getline(file, buff, ';')){
			ss << buff;
			ss >> nif;
			ss.clear();
		}

		if (getline(file, buff, ';')){
			ss << buff;
			ss >> hotel;
			ss.clear();
		}

		if (getline(file, buff, '\n')){
			ss << buff;
			ss >> arrival_time;
			ss.clear();
		}

		cout<<name<<" "<<nif<<" "<<hotel<<" "<<arrival_time<<endl;
		Passenger* p = new Passenger(name, nif);

		Reservation* res = new Reservation(hotels[hotel-1]->node, arrival_time, p);

		addReservation(res);

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

	cout<<"Press Enter to Continue...";
	cin.get();

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
	unsigned int hotel;
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

	Reservation* res = new Reservation(hotels[hotel-1]->node, arrival_time, p);

	addReservation(res);
}


void UserInterface::transferMenu(){

	vector<Node *> reserv_vec;
	Node *currNode = source;
	Node *nextNode;

	int i = 0;

	//puts the 10 first arrivals in the transfer
	cout << "Passengers to be transferred:\n";
	while(!reservations.empty() && i < MAX_PASSENGERS){
		reserv_vec.push_back(reservations.top()->getDestination());
		cout << reservations.top()->getClient()->getName()<<endl;
		reservations.pop();
		i++;
	}


	while(!reserv_vec.empty()){
		nextNode = currNode->getClosestNode(reserv_vec);
		cout<<"next: "<<nextNode->getId()<<endl<<reserv_vec.size()<<endl;cin.get();
		if(nextNode != currNode){
			transferTo(currNode->getId(),nextNode->getId());
			cout << "Client transfered!\n";
		}

		else{
			cout << "Client transfered!\n";
		}

		currNode = nextNode;


		for(i = 0; i < reserv_vec.size(); i++){
			if(reserv_vec[i]->getId() == currNode->getId()){
				reserv_vec.erase(reserv_vec.begin() + i);
				break;
			}
		}
	}

	nextNode = source;
	transferTo(currNode->getId(),nextNode->getId());
	cout << "\nBack at the airport!\n";

	return;
}

void UserInterface::mainMenu() {
	cout<<"Welcome!\n";
	cout<<"Please choose an option: \n";
	cout<<"1 - Add Reservation\n";
	cout<<"2 - Show Reservations\n";
	cout<<"3 - Plan Trip\n";
	cout<<"4 - Exit\n";
	cout<<"\nYour option: ";

	int op;
	cin>>op;
	cin.ignore(1000, '\n');

	while(op<1 || op>4)
		cout<<"Please choose a valid option: ";

	switch(op){
	case 1:
		cout<<"\n\n\n";
		reservationMenu();
		cout<<"\n\n\n";
		mainMenu();
		break;
	case 2:
		cout<<"\n\n\n";
		printReservations();
		cout<<"\n\n\n";
		mainMenu();
		break;
	case 3:
		cout<<"\n\n\n";
		transferMenu();
		cout<<"\n\n\n";
		break;
	case 4:
		cout<<"\nGoodBye!\n";
		exit(0);
	}
	cin.get();
}


void UserInterface::transferTo(unsigned long id_from, unsigned long id_dest){

	vector<Node *> path;


	graph->resetIndegrees();
	graph->dijkstraShortestPath(id_from);

	path = graph->getPath(id_from, id_dest);
	if(path.size() == 0)
		return;

	string oldRoadName = "1";

	for(unsigned int i=0; i<path.size()-1; i++){
		for(unsigned int j=0; j < path[i]->adj.size(); j++){
			if(path[i]->adj[j]->getDest()->getId() == path[i+1]->getId()){

				if(oldRoadName != path[i]->adj[j]->getRoad()->getName()){
					oldRoadName = path[i]->adj[j]->getRoad()->getName();
					cout<<"Turn to road ";
					if(oldRoadName.size() == 0)
						cout<<"Unknown Name"<<endl;
					else
						cout<<oldRoadName<<endl;

				}
			}
		}
		//cout<<" Passing Node "<<path[i]->getId()<<endl;
	}
}


