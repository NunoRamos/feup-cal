#include <iostream>
#include <cmath>

/**
 * \brief class that holds the geographical position of a certain Node
 */
class Coordinates{
	double lon,lat;

public:
	/**
	 * \brief basic class constructor
	 */
	Coordinates(double lon, double lat);

	/**
	 * \brief returns the longitude of the Node
	 */
	double getLongitude() const;

	/**
	 * \brief returns the latitude of the Node
	 */
	double getLatitude() const;
};


/**
 * \class that holds the geographical position of a certain Node as an x,y pair where x and y are the latitude and longitude in radians
 */
class Point{
	double x, y;

public:
	/**
	 * \brief basic class constructor
	 */
	Point(double x, double y);

	/**
	 * \brief returns the x coordinate of the Node
	 */
	double getX() const;

	/**
	 * \brief returns the y coordinate of the Node
	 */
	double getY() const;
};

/**
 * \brief function used to get the distance between two geographical locations
 *
 */
double getDistance(const Point c1,const Point c2);
