//TODO Alterar isto
/*
 * Coordinates.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: epassos
 */

#include "Coordinates.h"

Coordinates::Coordinates(float lon, float lat){
	this->lon = lon;
	this->lat = lat;
}

float Coordinates::getLatitude(){
	return lat;
}

float Coordinates::getLongitude(){
	return lon;
}


Point::Point(float x, float y){
	this->x = x;
	this->y = y;
}

float Point::getX(){
	return x;
}

float Point::getY(){
	return y;
}
