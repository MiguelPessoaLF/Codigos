#ifndef _ED1300_HPP_
#define _ED1300_HPP_
#include <iostream>
using std::cin ;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream ;
using namespace std;
template < typename A >
class erro
{
 private:
 A value;
 public: 
 erro()
 {
    value = 1;
 }
~erro()
 {
    value = 0;
 }
 bool erro_value (int value)
 {
    if (value == 0)
    {
        return false;
    }
    return true;
 }
   bool erro_name (string name)
 {
    if (name.size() == 0)
    {
      return true;
    }
    return false;
 }
};
#endif