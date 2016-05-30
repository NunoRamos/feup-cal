/*
 * Hotel.h
 *
 *  Created on: May 30, 2016
 *      Author: epassos
 */

#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include "Graph.h"

class Hotel {
	string name;
	Node *node;
	bool assigned;
public:
	/**
	 * \brief class constructor
	 *
	 * \arg name Name of the Hotel
	 * \arg n Node that refers to the position of the Hotel
	 */
	Hotel(string name, Node *n);

	/**
	 * \brief checks if the hotel is already assigned to a van
	 */
	bool getAssigned();

	/**
	 * \brief sets the assigned flag to represent the current state of the hotel
	 */
	void setAssigned(bool flag);

	/**
	 * \brief returns the name of the hotel
	 */
	string getName() const;

	/**
	 * \brief returns the node where the hotel is located
	 */
	Node *getNode() const;
	friend class UserInterface;
};




#endif /* SRC_HOTEL_H_ */
