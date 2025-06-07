#pragma once

#include "TradeManager.h"

class Strategy {
public:
  virtual Trade processTick(Tick t) = 0;
};
