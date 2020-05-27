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
	double cooperativeness[4]; //cooperativeness at status: 0 to 3
	int DNA[32];
}driver;

typedef class Racer
{
public:
	driver driver_object;
	racecar car_object;
	int season_points;
	int current_track;

	std::vector<double> lap_times; // self measured time
	int before_corner;
	double position_on_track;
	int status; //0: acceleration, 1: top speed, 2: braking 3: at cornering speed
	double current_speed; // [m/s]

	Racer(driver& d, racecar& rc);
	void new_track();
	double brake_before_corner();
}racer;

