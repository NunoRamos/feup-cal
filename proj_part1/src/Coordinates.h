#include <cmath>

class Coordinates{
	double lon,lat;

public:
	Coordinates(double lon, double lat);
	double getLongitude() const;
	double getLatitude() const;
};

class Point{
	double x, y;

public:
	Point(double x, double y);
	double getX() const;
	double getY() const;
};

double getDistance(const Coordinates c1,const Coordinates c2);
