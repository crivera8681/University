#ifndef student_H
#define student_H
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "studentfaculty.h"
#include "course.h"
using namespace std;

class Student:public StudentFaculty//this is the class Student with all of its attributes and methods
{
 protected:
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;
 public:
  Student();
  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  int getsYearOfStudy();
  string getsMajor();
  long getsAdvisorId();
  bool getCourseTaken(long courseId);
  void addACourse(Course course);
  void PrintCourses();
};

#endif
