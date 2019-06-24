#include "department.h"

long Department::nextDepartId = 100;//initializing a static variable of the class

Department::Department()//the default consructor
{
  id = nextDepartId;
  name = " ";
  location = " ";
  chairId = 0;
  nextDepartId++;
}

Department::Department(string depName, string depLoc, long depChairId)//a constructor with variables passed to it to set equal to the original attributes
{
  id = nextDepartId;
  name = depName;
  location = depLoc;
  chairId = depChairId;
  nextDepartId++;
}

void Department::PrintDepartment()const//the classes' print function
{
  cout<<"Department:"<<endl;
  cout<<"Id: "<<id<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Location: "<<location<<endl;
  cout<<"Chair Id: "<<chairId<<endl;
}

long Department::getdId()//get functions for the various attributes of the class
{
  return id;
}

string Department::getdName()
{
  return name;
}

string Department::getdLocation()
{
  return location;
}

long Department::getdChairId()
{
  return chairId;
}

void Department::setdChairId(long depChairId)//set functions for the attributes of the class
{
  id = depChairId;
}
