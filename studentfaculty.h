#ifndef studentfaculty_H
#define studentfaculty_H
#include<iostream>
#include<string>
using namespace std;

class StudentFaculty//this is the class StudentFaculty with all of its attributes and methods
{
 protected:
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  long getsfId();
  string getsfName();
  string getsfEmail();
  string getsfAddress();
  string getsfDateofBirth();
  string getsfGender();
};

#endif
