#include"faculty.h"

long Faculty::nextFacultyId = 600;//initializing a static variable of the class

Faculty::Faculty()//the default consructor
{
  id = 0;
  name = " ";
  email = " ";
  address = " ";
  dateOfBirth = " ";
  gender = " ";
  salary = 0;
  yearOfExp = 0;
  departId = 0;
  ++ nextFacultyId;
}

Faculty::Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)//a constructor with variables passed to it to set equal to the original attributes
{
  id = nextFacultyId;
  name = " ";
  email = " ";
  address = " ";
  dateOfBirth = " ";
  gender = " ";
  name = fName;
  email = fEmail;
  address = fAddress;
  dateOfBirth = fDateOfBirth;
  gender = fGender;
  salary = fSalary;
  yearOfExp = fYearOfExp;
  departId = fDepId;
  ++nextFacultyId;
}

float Faculty::getfSalary()//get functions for the various attributes of the class
{
  return salary;
}

int Faculty::getfYearOfExp()
{
  return yearOfExp;
}

long Faculty::getfDepartId()
{
  return departId;
}
long Faculty::getfNextFacultyId()
{
  return nextFacultyId;
}
