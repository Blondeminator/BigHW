#include <iostream>
#include "Racers.h"
#include <vector>
#include <fstream>

using namespace std;

int random_seed = 0;
double delta_t = 0.1;

vector<vector<pair<double, int>>> tracks;
vector<pair<double, int>> track_read;


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

