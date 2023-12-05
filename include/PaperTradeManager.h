#pragma once

#include "TradeManager.h"
#include "VirtualBank.h"

class PaperTradeManager : public TradeManager {
public:
  int holdQuantity;
  VirtualBank *virtual_bank;
  PaperTradeManager(VirtualBank *virtual_bank);
  void performBuy(Trade trade);
  void performSell(Trade trade);
  bool canBuy(Trade trade);
  bool canSell(Trade trade);
  bool squareOff(Tick last_tick);
};
