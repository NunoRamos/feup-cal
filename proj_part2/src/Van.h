/*
 * Van.h
 *
 *  Created on: May 30, 2016
 *      Author: epassos
 */

#ifndef SRC_VAN_H_
#define SRC_VAN_H_

#include "Reservation.h"
#include "Hotel.h"

#define MAX_PASSENGERS 10

class Van {
	vector<Hotel> hotelZone;
	vector<Reservation> passengers;

public:
	/**
	 * \brief basic class constructor
	 *
	 * \arg hz vector of hotels to which this van will transfer clients
	 */
	Van(vector<Hotel> hz){
		this->hotelZone = hz;
	}

	//PART 2
	/**
	 * \brief returns the hotels served by the
	 */
	vector<Hotel> getHotels() const{
		return hotelZone;
	}

	friend class UserInterface;
};


#endif /* SRC_VAN_H_ */
