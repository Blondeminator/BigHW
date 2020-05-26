#include <iostream>
#include "Racers.h"
#include <vector>
#include <fstream>

using namespace std;

int random_seed = 0;
double delta_t = 0.1;
int number_of_contestants = 20;
int number_of_laps = 10;
double q_top_speed = 1; // 1 genes worth of bonus top speed
double q_acceleration = 1; // 1 genes worth of bonus acceleration
double q_cornering_speed = 1; // 1 genes worth of bonus cornering speed
 
vector<vector<pair<double, int>>> tracks;
vector<pair<double, int>> track_read;

vector<racecar> cars;
vector<driver> drivers;
vector<racer> racers; //car + driver -> racer agent
double current_time = 0;

void make_cars(vector<racecar>& mc_c) {
	for (int i = 0; i < number_of_contestants; i++) {
		racecar new_racecar;
		new_racecar.id = i;
		for (int j = 0; j < 18; j++) {
			double random = (double)rand() / RAND_MAX;
			if (random < 0.5) {
				new_racecar.DNA[j] = 0;
			}
			else new_racecar.DNA[j] = 1;
		}
		new_racecar.top_speed = 70 + ((new_racecar.DNA[0] + new_racecar.DNA[1] + new_racecar.DNA[2]) - (new_racecar.DNA[3] + new_racecar.DNA[4] + new_racecar.DNA[5]) - (new_racecar.DNA[12] + new_racecar.DNA[13] + new_racecar.DNA[14]) + (new_racecar.DNA[15] + new_racecar.DNA[16] + new_racecar.DNA[17])) * q_top_speed;
		new_racecar.acceleration = 10 + (-new_racecar.DNA[0] - new_racecar.DNA[1] - new_racecar.DNA[2] + (new_racecar.DNA[3] + new_racecar.DNA[4] + new_racecar.DNA[5]) + (new_racecar.DNA[6] + new_racecar.DNA[7] + new_racecar.DNA[8]) - (new_racecar.DNA[9] + new_racecar.DNA[10] + new_racecar.DNA[11]))* q_acceleration;
		new_racecar.cornering_speed = 30 + ((new_racecar.DNA[9] + new_racecar.DNA[10] + new_racecar.DNA[11]) - (new_racecar.DNA[6] + new_racecar.DNA[7] + new_racecar.DNA[8]) + (new_racecar.DNA[12] + new_racecar.DNA[13] + new_racecar.DNA[14]) - (new_racecar.DNA[15] + new_racecar.DNA[16] + new_racecar.DNA[17])) * q_cornering_speed;
		mc_c.push_back(new_racecar);
	}
}



void make_drivers(vector<driver>& md_d) {
	for (int i = 0; i < number_of_contestants; i++) {
		driver new_driver;
		for (int j = 0; j < 32; j++) {
			double random = (double)rand() / RAND_MAX;
			if (random < 0, 5) {
				new_driver.DNA[j] = 0;
			}
			else new_driver.DNA[j] = 1;
		}
		new_driver.id = i;
		int DNA_0 = 0;
		int DNA_1 = 0;
		int DNA_2 = 0;
		int DNA_3 = 0;
		for (int j = 0; j < 8; j++) {
			DNA_0 += new_driver.DNA[j];
		}
		for (int j = 8; j < 16; j++) {
			DNA_1 += new_driver.DNA[j];
		}
		for (int j = 16; j < 24; j++) {
			DNA_2 += new_driver.DNA[j];
		}
		for (int j = 24; j < 32; j++) {
			DNA_3 += new_driver.DNA[j];
		}


		new_driver.cooperativeness[0] = DNA_0 / 8;
		new_driver.cooperativeness[1] = DNA_1 / 8;
		new_driver.cooperativeness[2] = DNA_2 / 8;
		new_driver.cooperativeness[3] = DNA_3 / 8;
		md_d.push_back(new_driver);
	}
}

void end_race(vector<Racer>& er_r) {
	// +1 pont a leggyorsabb körért
	// +10 pont a nyertesnek +9 a 2-nak.... (Nyertes akinek a köridõ összege a legkisebb)
	for (int i = 0; i < er_r.size(); i++) {
		racers[i].new_track();
	}
}

void make_racers(vector<Racer>& mr_r, vector<racecar>& mr_c, vector<driver>& mr_d) {
	for (int i = 0; i < number_of_contestants; i++) {
		racers.push_back(racer(mr_d[i], mr_c[i]));
	}
}

void Is_brake_needed(racer& r) {
	if ((r.position_on_truck + r.brake_before_corner()) > tracks[r.current_track][r.before_corner].first) {
		r.status = 2;
	}
}

void Is_at_top_speed(racer& r) {
	if (r.current_speed >= r.car_object.top_speed) {
		r.status = 1;
		r.current_speed = r.car_object.top_speed;
	}
}

void status_check() {
	for (int i = 0; i < racers.size(); i++) {
		if (racers[i].status == 0) { // acc
			Is_at_top_speed(racers[i]);
			Is_brake_needed(racers[i]);
		}
		if (racers[i].status == 1) { // top_speed
			Is_brake_needed(racers[i]);
		}
		if (racers[i].status == 2) { // brake

		}
		if (racers[i].status == 3) { //at cornering_speed

		}
	}
}



int main()
{
	srand(0);
	ifstream file;
	file.open("Tracks.txt");
	if (file.is_open()) {
		double place;
		int direction;
		while (file.good()) {
			file >> place >> direction;
			if (place == -1 && direction == 0) {
				tracks.push_back(track_read);
				track_read.clear();
			}
			else {
				track_read.push_back(make_pair(place,direction));
			}
		}
	}
	else {
		cout << "File not found or could not be opened!" << endl;
	}


}

