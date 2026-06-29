#pragma once
#include <string>
#include "common.h"

using namespace std;

class CurrencyConversions {
 public:
  static void removeCommasFromCurrency(string& str);
  static REAL readWithPrecision(string const& str, size_t const p);
};
