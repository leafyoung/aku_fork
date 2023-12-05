#include "../include/Tick.h"
#include <iostream>

using namespace std;

void Tick::dump() {
  cout << "Dumping tick values" << endl;
  cout << "Timestamp - " << this->time << endl;
  cout << "Open - " << to_string(this->open) << endl;
  cout << "High - " << to_string(this->high) << endl;
  cout << "Low - " << to_string(this->low) << endl;
  cout << "Close - " << to_string(this->close) << endl;
  cout << "Adjust Close - " << to_string(this->adjust_close) << endl;
  cout << "Volume - " << this->volume << endl;

  cout << endl;
}