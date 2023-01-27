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


  dat.push_back("sup");
  dat.push_back("er");
  dat.push_back("cali");
  dat.push_back("frag");
  dat.push_back("il");
  dat.push_back("istic");
  dat.push_back("expi");
  dat.push_back("alo");
  dat.push_back("doc");
  dat.push_back("ious");
	dat.push_back("end");
  dat.pop_back();
  cout << dat.back() << " size is: " << dat.size() << endl;
  // // prints: 8 7 9
  // cout << dat.size() << end;  // prints 3 since there are 3 strings stored
}
