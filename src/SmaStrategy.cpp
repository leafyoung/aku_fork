#include "../include/SmaStrategy.h"
#include "../include/Trade.h"
#include <iostream>

using namespace std;

using Move = Trade::Move;

Trade SmaStrategy::processTick(Tick tick) {
  int quantity = 10;
  int smaDayRange = 5;
  // int differenceTolerance = 100;
  Trade::Move mv;

  this->tickCount += 1;
  this->totalClosingPrice += tick.close;

  // following block will ensure that if we are making good profit exit
  // position.
  if (this->lastBoughtPrice != 0 && (tick.close - this->lastBoughtPrice) > 10) {
    mv = Move::SELL;
    if (DEBUG_FLAG) {
      cout << "SmaStrategy: Safe SELL SIGNAL generated" << endl;
    }
    return Trade(mv, quantity, tick);
  }

  if (this->tickCount >= smaDayRange) {
    REAL ma = this->totalClosingPrice / smaDayRange;
    this->tickCount = 0;
    this->totalClosingPrice = 0;

    if (tick.close > ma) {
      this->isPosition = true;
      mv = Move::BUY;
      this->lastBoughtPrice = tick.close;
      if (DEBUG_FLAG) {
        cout << "SmaStrategy: BUY SIGNAL generated" << endl;
      }
    } else {
      mv = Move::PASS;
      if (DEBUG_FLAG) {
        cout << "SmaStrategy: PASS SIGNAL generated" << endl;
      }
    }
  } else {
    mv = Move::PASS;
    if (DEBUG_FLAG) {
      cout << "SmaStrategy: PASS SIGNAL generated" << endl;
    }
  }

  return Trade(mv, quantity, tick);
}