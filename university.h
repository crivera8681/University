#ifndef university_H
#define university_H
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include "department.h"
#include "faculty.h"
#include "student.h"
using namespace std;

class University//this is the class University with all of its attributes and methods
{
 public:
  vector<Department> departments;
  vector<Student> students;
  vector<Course> courses;
  vector<Faculty> faculties;
  static bool failure;
  static bool success;

 public:
  University();
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool CreateNewStudent(string sName, string sDepId, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);

  bool ListFacultiesInDepartment(long departId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListCoursesOfADepartment(long departId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListStudentsOfAFaculty(long facultyId);

  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);

  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  bool checkDeptExists(long fDepId);//RemoveADepartment, CreateNewCourse, CreateNewFaculty, ListFacultiesDepartment, ListCoursesOfADepartment, AssignDepartmentChair
  bool checkFacultyExists(long fDepId);//AssignInstructorToCourse, CreateNewDepartment, CreateNewStudent, CreateNewCourse, RemoveAFaculty, ListCoursesTaughtByFaculty, ListStudentsOfAFaculty, AssignDepartmentChair
  bool checkDeptName(string deptName);//CreateNewStudent
  bool checkStudentExists(long sStdId);//RemoveAStudent, ListCoursesTakenByStudent, AddACourseForAStudent, DropACourseForStudent
  bool checkCourseExists(long cCRN);//RemoveACourse, AddACourseForAStudent, DropACourseForAStudent, AssignInstructorToCourse
  bool isMyTeacher(Student st, long fId);//ListStudentOfAFaculty
  bool ProcessTransactionFile(string fileName);
};

#endif
