#pragma once

#include <iostream>

using namespace std;

class staticmsgs {
public:
  static string noinputfile;
  static string printargs;
};

string staticmsgs::noinputfile =
    "No Input file specified. Input file is a mandatory argument";
string staticmsgs::printargs = "Printing all arugments ...";