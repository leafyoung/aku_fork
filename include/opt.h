#include "cxxopts.h"

using namespace std;

int argc_new = 6;
char *argv_new[] = {(char *)"bin/aku",
                    (char *)"-i",
                    (char *)"sample_inputs/MARUTI.NS.csv",
                    (char *)"-o",
                    (char *)"abc.csv",
                    (char *)"-d",
                    nullptr};
argv = argv_new;

auto result = options.parse(argc_new, argv);

// print help if help specified
if (result.count("help")) {
  cout << options.help() << endl;
  exit(0);
}

// set debug mode if specified
// bool debug = result["debug"].as<bool>();

// check if input file is specified or not.
// exit if not specified
if (result.count("input")) {
  input_file = result["input"].as<string>();
} else {
  cout << staticmsgs::noinputfile << endl;
  cout << options.help() << endl;
  exit(0);
}

// set path to output file
output_file = result["output"].as<string>();

if (DEBUG_FLAG) {
  cout << staticmsgs::printargs << endl;
  cout << "Path to input file " << input_file << endl;
  cout << "Path to output file " << output_file << endl;
}
