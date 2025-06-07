#pragma once

#include "TickManager.h"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

// Note: remove method:  Tick getNextTick(Tick last_tick);

/* Example Tick Manager */

/* Following Manager is only for testing purpose
Do not use this manager in prod */

class RandomTickManager : public TickManager {
  seed_seq seed;
  mt19937 generator;
  uniform_int_distribution<int> distribution_int;
  uniform_real_distribution<double> distribution_double;

public:
  RandomTickManager() : seed{43}, generator(seed) {
    cout << distribution_int(generator) << endl;
    cout << distribution_int(generator) << endl;
    cout << distribution_int(generator) << endl;
    cout << distribution_int(generator) << endl;
  }
  Tick getNextTick();

private:
  int genRandomInt();
  float genRandomFloat();
};