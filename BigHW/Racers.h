#pragma once
#include <vector>

typedef struct racecar {
	int id;
	double top_speed; //70 [m/s]
	double acceleration; //10 [m/s^2]
	double cornering_speed; //30 [m/s]
	int DNA[18];
}racecar;

typedef struct driver {
	int id;
	double cooperativeness;
	int DNA[32];
}driver;

typedef class Racer
{
	driver driver_object;
	racecar car_object;
	double position_on_truck;
	std::vector<double> lap_times; // self measured time
	int status; //0: acceleration, 1: top speed, 2: braking 3: at cornering speed
	double break_before_corner; //how far back the breaking begins [m]

	Racer(driver& d, racecar& rc);
	void new_track();
}racer;

