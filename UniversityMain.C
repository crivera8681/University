/*
Carlos Rivera

The purpose of this program is to create a university and a record of all the students, faculty, courses etc.
The program can add courses for a student, create new departments, and complete other tasks having to do with university creation and management.

*/

#include<iostream>//including the necessary directories and files associated with this program
#include<fstream>
#include "course.h"
#include "course.cpp"
#include "university.h"
#include "university.cpp"
#include "faculty.h"
#include "faculty.cpp"
#include "student.h"
#include "student.cpp"
#include "department.h"
#include "department.cpp"
#include "studentfaculty.h"
#include "studentfaculty.cpp"
using namespace std;

int main()//main program which creates an object of University and then passes that object as well and the transaction file to a method in the university class.
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");

  return 0;
}
