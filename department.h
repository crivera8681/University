#ifndef department_H
#define department_H
#include<iostream>
#include<string>
using namespace std;

class Department//this is the class Department with all of its attributes and methods
{
 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;

 public:
  Department();
  Department(string depName, string depLoc, long depChairId);
  long getdId();
  string getdName();
  string getdLocation();
  long getdChairId();
  void setdChairId(long depChairId);
  void PrintDepartment()const;
};

#endif
