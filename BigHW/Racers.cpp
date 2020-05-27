#include "Racers.h"


Racer::Racer(driver& d, racecar& rc) {
	driver_object = d;
	car_object = rc;
	status = 0;
	season_points = 0;
	current_track = -1;
	before_corner = -1;
}

void Racer::new_track() {
	position_on_track = 0;
	status = 0;
	lap_times.clear();
	lap_times.push_back(0);
	status = 0;
	current_track++;
	before_corner = 0;
}

double Racer::brake_before_corner() {
	double delta_v = current_speed - car_object.cornering_speed;
	double t = delta_v / (car_object.acceleration * 2);
	double distance = 10 + (car_object.acceleration * 2) / 2 * pow(t, 2) +  car_object.cornering_speed * t;
	return distance;
}