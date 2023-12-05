#pragma once

#include "Strategy.h"

class SmaStrategy : public Strategy {
public:
  // vector<Tick> tickBuffer;
  bool isPosition = false;
  int tickCount;
  REAL totalClosingPrice;
  REAL lastBoughtPrice;
  Trade processTick(Tick t);
};