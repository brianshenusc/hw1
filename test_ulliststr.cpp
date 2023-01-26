#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");
  dat.push_back("11");
  // dat.push_front("9");
  // dat.push_back("9");
  // dat.pop_back();
  cout << dat.front() << dat.back() << " size is: " << dat.size() << endl;
  // // prints: 8 7 9
  // cout << dat.size() << end;  // prints 3 since there are 3 strings stored
}
