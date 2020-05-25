#pragma once
#include <vector>

typedef struct racecar {
	double top_speed; //70
	double acceleration; //10
	double cornering_speed; //30
	int DNA[18];
}racecar;

typedef struct driver {
	double cooperativeness;
	int DNA[32];
}driver;

typedef class Racer
{
	driver driver_object;
	racecar car_object;
	double position_on_truck;
	vector<double> lap_times; // self measured time
	int status; //0: acceleration, 1: top speed, 2: braking 3: at cornering speed
	std::vector<std::pair<double, int>>& track;

	//Racer();
	Racer(driver& d, racecar& rc);
	void reset();
}racer;

