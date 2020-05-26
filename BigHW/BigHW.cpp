#include <iostream>
#include "Racers.h"
#include <vector>
#include <fstream>

using namespace std;

int random_seed = 0;
double delta_t = 0.1;
int number_of_contestants = 20;
int number_of_laps = 10;

vector<vector<pair<double, int>>> tracks;
vector<pair<double, int>> track_read;

vector<racecar> cars;
vector<driver> drivers;
vector<racer> racers; //car + driver -> racer agent
double current_time = 0;

void make_cars(vector<racecar>& mc_c) {

}

void make_drivers(vector<driver>& md_d) {

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

void status_check() {
	for (int i = 0; i < racers.size(); i++) {
		if (racers[i].status == 0) { // acc
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

