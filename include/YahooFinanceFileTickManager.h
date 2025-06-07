#pragma once

#include "Tick.h"
#include "TickManager.h"
#include <iostream>
#include <vector>

using namespace std;

class YahooFinanceFileTickManager : public TickManager {
public:
  YahooFinanceFileTickManager(string file_path);
  Tick getNextTick();
  int tick_counter;
  vector<Tick> tick_store;
  Tick parseTickFromString(string line);
  INT parseDateFromString(string date);
  bool hasNextTick();
};