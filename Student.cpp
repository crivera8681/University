#include "student.h"

long Student::nextStId = 500;//initializing a static variable of the class

Student::Student()//the default consructor
{
  id = 0;
  name = " ";
  email = " ";
  address = " ";
  dateOfBirth = " ";
  gender = " ";
  yearOfStudy = 0;
  major = " ";
  advisorId = 0;
  nextStId++;
}

Student::Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)//a constructor with variables passed to it to set equal to the original attributes
{
  id = nextStId;
  name = sName;
  email = sEmail;
  address = sAddress;
  dateOfBirth = sDateOfBirth;
  gender = sGender;
  yearOfStudy = sYearOfStudy;
  major = sMajor;
  advisorId = sAdvisorId;
  nextStId++;
}

int Student::getsYearOfStudy()//get functions for the various attributes of the class
{
  return yearOfStudy;
}
string Student::getsMajor()
{
  return major;
}
long Student::getsAdvisorId()
{
  return advisorId;
}
bool Student::getCourseTaken(long courseId)
{

}

void Student::addACourse(Course course)
{
  coursesTaken.push_back(course);
}

void Student::PrintCourses()
{
  for(int i = 0; i < coursesTaken.size(); i++)
    cout<<setw(20)<<left<<coursesTaken[i].getcName()<<setw(20)<<left<<coursesTaken[i].getcCRN()<<endl;
}
