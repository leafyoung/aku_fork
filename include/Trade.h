#pragma once

#include "Tick.h"
#include "Trade.h"
#include <iostream>

using namespace std;

class Trade {
public:
  enum class Move { BUY, SELL, PASS };
  Move mv;
  int quantity;
  Tick tick;

  Trade(Trade::Move mv, int quantity, Tick tick): mv(mv), quantity(quantity), tick(tick) { }

  void dump() {
    cout << "Dumping a trade sequence" << endl;
    const string trade_move = [this]() {
      if (this->mv == Move::BUY)
        return "BUY";
      if (this->mv == Move::SELL)
        return "SELL";
      return "PASS";
    }();

    cout << "TradeMove - " << trade_move << endl;
    cout << "Trade quantity - " << this->quantity << endl;
    cout << "Tick Info -- " << endl;
    this->tick.dump();
    cout << endl;
  }
};
