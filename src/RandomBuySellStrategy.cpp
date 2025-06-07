#include "../include/RandomBuySellStrategy.h"
#include "Trade.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
using Move = Trade::Move;

Trade RandomBuySellStrategy::processTick(Tick tick) {

  // static random_device rd;
  // static mt19937 mt(rd());

  static seed_seq seed{43};
  static mt19937 mt(seed);
  int randomMove;

  int quantity = 10;
  Trade::Move mv;

  // srand((unsigned int)time(NULL));
  // randomMove = min + (rand() % static_cast<int>(max - min + 1));

  uniform_int_distribution<int> dist(1, 3);
  randomMove = dist(mt);

  if (randomMove == 1) {
    mv = Move::BUY;
    if (DEBUG_FLAG) {
      cout << "RandomBuySellStrategy: BUY SIGNAL generated" << endl;
    }
  }

  if (randomMove == 2) {
    mv = Move::SELL;
    if (DEBUG_FLAG) {
      cout << "RandomBuySellStrategy: SELL SIGNAL generated" << endl;
    }
  }

  if (randomMove == 3) {
    mv = Move::PASS;
    if (DEBUG_FLAG) {
      cout << "RandomBuySellStrategy: PASS SIGNAL generated" << endl;
    }
  }

  // mv = Move::BUY;

  return Trade(mv, quantity, tick);
}