#include <iostream>
#include "Racers.h"
#include <vector>

using namespace std;

vector<pair<double, int>> truck0;



int main()
{
    truck0.resize();
    for (int i = 0; i < 500; i++) {
        truck0[i].first = i;
        truck0[i].second = 0;
    }
    for (int i = 501; i < 1500; i++) {
        truck0[i].first = i;
        truck0[i].second = 0;
    }
    for (int i = 1501; i < 2500; i++) {
        truck0[i].first = i;
        truck0[i].second = 0;
    }
    for (int i = 2501; i < 3500; i++) {
        truck0[i].first = i;
        truck0[i].second = 0;
    }
    for (int i = 3501; i < 4000; i++) {
        truck0[i].first = i;
        truck0[i].second = 0;
    }
    truck0[500].first = -1;
    truck0[1500].first = -1;
    truck0[2500].first = -1;
    truck0[3500].first = -1;
   
}

