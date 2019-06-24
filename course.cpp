#include "course.h"

long Course::nextCRN = 200;//initializing a static variable of the class

Course::Course()//the default consructor
{
  CRN = 0;
  maxAvailableSeats = 0;
  name = " ";
  departId = 0;
  assignedSeats = 0;
  isTaughtBy = 0;
  nextCRN++;
}

Course::Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat)//a constructor with variables passed to it to set equal to the original attributes
{
  CRN = nextCRN;
  name = cName;
  departId = cDepId;
  isTaughtBy = cTaughtBy;
  maxAvailableSeats = cMaxSeat;
  nextCRN++;
}

void Course::PrintCourse()const//the classes' print function
{
  cout<<"Course:"<<endl;
  cout<<"CRN: "<<CRN<<endl;
  cout<<"Max Available Seats: "<<maxAvailableSeats<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Dep Id: "<<departId<<endl;
  cout<<"Assigned Seats: "<<assignedSeats<<endl;
  cout<<"Taught By: "<<isTaughtBy<<endl;
}

long Course::getcCRN()
{
  return CRN;
}
int Course::getcMaxAvailableSeats()
{
  return maxAvailableSeats;
}
string Course::getcName()
{
  return name;
}
long Course::getcDepartId()
{
  return departId;
}

long Course::getcAssignedSeats()
{
  return assignedSeats;
}

long Course::getcIsTaughtBy()
{
  return isTaughtBy;
}

void Course::setcIsTaughtBy(long cTaughtBy)
{
  isTaughtBy = cTaughtBy;
}

void Course::incrementAssignedSeats()
{
  assignedSeats++;
}
