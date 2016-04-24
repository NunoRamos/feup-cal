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

double getDistance(const Point c1,const Point c2){

	double dist = sqrt((c1.getX() - c2.getX())*(c1.getX() - c2.getX()) +
			(c1.getY() - c1.getY()) * (c1.getY() - c1.getY()));


	std::cout<<"dist = "<<dist<<std::endl;
	return dist;
}
