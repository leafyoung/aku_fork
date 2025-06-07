#pragma once
#include <vector>

#include "Tick.h"
#include "Trade.h"

using namespace std;

class TradeManager {
public:
  int quantity;
  vector<Trade> trades;
  int performTrade(Trade trade);

  virtual void performBuy(Trade trade) = 0;
  virtual void performSell(Trade trade) = 0;
  virtual bool canBuy(Trade trade) = 0;
  virtual bool canSell(Trade trade) = 0;
  virtual bool squareOff(Tick last_tick) = 0;

  int performBuyInternal(Trade trade);
  int performSellInternal(Trade trade);
  void dumpTrades();
};
