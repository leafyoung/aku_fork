#include "../include/CurrencyConversions.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void CurrencyConversions::removeCommasFromCurrency(string &str) {
  str.erase(remove(str.begin(), str.end(), ','), str.end());
}

REAL CurrencyConversions::readWithPrecision(string const &str, size_t const p) {
  stringstream sstream;
  sstream << setprecision(p) << fixed << str << endl;

  REAL d;
  sstream >> d;

  return d;
}
