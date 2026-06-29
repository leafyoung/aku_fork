#pragma once

#include <iostream>
#include "Tick.h"

class TickManager {
 public:
  virtual Tick getNextTick() = 0;
  virtual bool hasNextTick() = 0;
};
