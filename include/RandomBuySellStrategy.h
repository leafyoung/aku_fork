#pragma once

#include "Strategy.h"

class RandomBuySellStrategy : public Strategy {
public:
  Trade processTick(Tick t);
};