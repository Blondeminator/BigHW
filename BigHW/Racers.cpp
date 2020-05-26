#include "Racers.h"


Racer::Racer(driver& d, racecar& rc) {
	driver_object = d;
	car_object = rc;
	position_on_truck = 0;
	lap_times.push_back(0);
	status = 0;
}

void Racer::new_track() {
	position_on_truck = 0;
	status = 0;
	lap_times.clear();
	lap_times.push_back(0);
	status = 0;
}

double Racer::brake_before_corner() {

}