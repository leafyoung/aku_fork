#pragma once

#include "Tick.h"
#include <iostream>

class TickManager {
public:
  virtual Tick getNextTick() = 0;
  virtual bool hasNextTick() = 0;
};
