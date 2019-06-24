#ifndef faculty_H
#define faculty_H
#include<iostream>
#include<string>
#include "studentfaculty.h"
using namespace std;

class Faculty:public StudentFaculty //this is the class Faculty with all of its attributes and methods
{
 protected:
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;
 public:
  Faculty();
  Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  float getfSalary();
  int getfYearOfExp();
  long getfDepartId();
  long getfNextFacultyId();
};

#endif
