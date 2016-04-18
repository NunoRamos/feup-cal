//TODO Alterar isto
/*
 * Coordinates.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: epassos
 */

#include "Coordinates.h"

Coordinates::Coordinates(double lon, double lat){
	this->lon = lon;
	this->lat = lat;
}

double Coordinates::getLatitude() const{
	return lat;
}

double Coordinates::getLongitude() const{
	return lon;
}


Point::Point(double x, double y){
	this->x = x;
	this->y = y;
}

double Point::getX() const{
	return x;
}

double Point::getY() const{
	return y;
}

double getDistance(const Coordinates c1,const Coordinates c2){

	return sqrt((c1.getLatitude() - c2.getLatitude())*(c1.getLatitude() - c2.getLatitude()) *
			(c1.getLongitude() -c1.getLongitude()) * (c1.getLongitude() - c1.getLongitude()));
}
