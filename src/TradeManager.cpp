#include "../include/TradeManager.h"
#include "../include/Trade.h"
#include <iostream>

using namespace std;

using Move = Trade::Move;

int TradeManager::performTrade(Trade trade) {
  if (trade.mv == Move::BUY) {
    this->performBuyInternal(trade);
  }
  if (trade.mv == Move::SELL) {
    this->performSellInternal(trade);
  }

  return 0;
}

int TradeManager::performBuyInternal(Trade trade) {
  if (this->canBuy(trade)) {
    if (DEBUG_FLAG) {
      string trade_log = "Bought - " + to_string(trade.quantity) + " at " +
                         to_string(trade.tick.close) + " on " +
                         to_string(trade.tick.time);
    }

    this->trades.push_back(trade);
    this->quantity += trade.quantity;
    this->performBuy(trade);
    return 1;
  }

  return 0;
}

int TradeManager::performSellInternal(Trade trade) {
  if (this->canSell(trade)) {
    if (DEBUG_FLAG) {
      string trade_log = "Sold - " + to_string(trade.quantity) + " at " +
                         to_string(trade.tick.close) + " on " +
                         to_string(trade.tick.time);
    }

    this->trades.push_back(trade);
    this->quantity -= trade.quantity;
    this->performSell(trade);
    return 1;
  }

  return 0;
}

void TradeManager::dumpTrades() {
  cout << "Printing all the trades" << endl;
  cout << endl;

  for (auto trade : this->trades) {
    trade.dump();
    cout << endl;
  }
  cout << endl;
}