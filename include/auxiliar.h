#ifndef _AUXILIAR_H_
#define _AUXILIAR_H_

#include <string>
using std::string;
#include <algorithm>
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
#include <set>
using std::set;

string stringToUpper(string str);

vector<string> splitString(string& linha, char delimitador);

bool isNumeric(string str);

string askForString(istream& is, string msg, bool acceptNull = false);

int askForInteger(istream& is, string msg, bool acceptNegative = false, bool acceptZero = false);

double askForDouble(istream& is, string msg, bool acceptNegative = false, bool acceptZero = false);

#endif