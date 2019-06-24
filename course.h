#ifndef course_H
#define course_H
#include<iostream>
#include<string>
using namespace std;

class Course//this is the class Course with all of its attributes and methods
{
 protected:
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;
 public:
  Course();
  Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  long getcCRN();
  int getcMaxAvailableSeats();
  string getcName();
  long getcDepartId();
  long getcAssignedSeats();
  long getcIsTaughtBy();
  void PrintCourse()const;
  void setcIsTaughtBy(long cTaughtBy);
  void incrementAssignedSeats();
};

#endif
