#include <fstream>
#include <iostream>
#include <random>

#include "../include/staticmsgs.h"

#include "../include/Tick.h"
#include "../include/TickManager.h"

#include "../include/RandomTickManager.h"
#include "../include/YahooFinanceFileTickManager.h"

#include "../include/RandomBuySellStrategy.h"
#include "../include/SmaStrategy.h"
#include "../include/Strategy.h"

#include "../include/PaperTradeManager.h"
#include "../include/TradeManager.h"

#include "../include/VirtualBank.h"

using namespace std;

int main(int argc, char **argv) {
  /* Everything related to command-line options */
  string input_file{"sample_inputs/MARUTI.NS.csv"};
  string output_file{"output.csv"}; // path to input file
                                    // path to output file
  /* End everything related to command-line options */

  /* Initialise tick manager*/
  TickManager *tick_manager;
  // tick_manager = new RandomTickManager();
  tick_manager = new YahooFinanceFileTickManager(input_file);

  /* Initialise strategy */
  Strategy *strategy;
  // strategy = new RandomBuySellStrategy();
  strategy = new SmaStrategy();

  /*Initialise a virtual bank*/
  VirtualBank *virtual_bank;
  REAL bank_balance = 100000;
  virtual_bank = new VirtualBank(bank_balance);

  /* Initialise trade manager */
  TradeManager *trade_manager;
  trade_manager = new PaperTradeManager(virtual_bank);

  Tick last_traded_tick;
  /* Start the core event-loop */
  while (tick_manager->hasNextTick()) {
    last_traded_tick = tick_manager->getNextTick();
    // t.dump();

    Trade tr = strategy->processTick(last_traded_tick);
    trade_manager->performTrade(tr);
  }

  trade_manager->squareOff(last_traded_tick);
  trade_manager->dumpTrades();

  string final_bank_balance = to_string(virtual_bank->getBankBalance());
  string profit_or_loss =
      to_string(virtual_bank->getBankBalance() - bank_balance);

  cout << "Total Bank Balance: " << final_bank_balance << endl;
  cout << "Profit or loss: " << profit_or_loss << endl;

  return 0;
}
