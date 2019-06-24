#include "university.h"

bool University::failure = false;//static variables that are set to false and true values
bool University::success = true;//these will be passed back from almost ever method to know if the method was successful or not

University::University()
{}

bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)//this method creates a new department in the university
{
  bool foundId = checkFacultyExists(depChairId);//checking the variable to see if it exists in the university

  if(depChairId == 0)
    {
      cout<<"The chair is not yet known."<<endl;
    }
  else if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<depChairId<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }

  Department obj(depName, depLoc, depChairId);//creates an object of the class and pushes the obj with all the information passed to it into the vector
  departments.push_back(obj);

  return(University::success);
}

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)//this method creates a new student in the universtiy
{
  bool foundName = checkDeptName(sMajor);//checking the variable to see if it exists in the university
  bool foundId = checkFacultyExists(sAdvisorId);//checking the variable to see if it exists in the university
  
  if(sMajor == " ")
    {
      cout<<"The student has not chosen a Major."<<endl;
    }
  else if(foundName == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<sMajor<<" is a department name that does not exist."<<endl;
      return(University::failure);
    }

  if(sAdvisorId == 0)
    {
    cout<<"The student has either not chosen an advisor or does not need one."<<endl;
    }
  else if(foundId == false)
    {
      cout<<sAdvisorId<<" is an Advisor Id that does not exist."<<endl;
      return(University::failure);
    }

  Student obj(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);//creates an object of the class and pushes the obj with all the information passed to it into the vector
  students.push_back(obj);

  return(University::success);
}

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)//this method creates a new course for the university
{
  bool foundId = checkFacultyExists(cTaughtBy);//checking the variable to see if it exists in the university
  bool foundDept = checkDeptExists(cDepId);//checking the variable to see if it exists in the university

  if(cTaughtBy == 0)
    {
      cout<<"No one is assigned to teach this course."<<endl;
    }
  else if(foundId == false)
    {
      cout<<cTaughtBy<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }
  if(foundDept == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<cDepId<<" is a department Id that does not exist"<<endl;
      return(University::failure);
    }

  Course obj(cName, cDepId, cTaughtBy, cMaxSeat);//creates an object of the class and pushes the obj with all the information passed to it into the vector
  courses.push_back(obj);

  return(University::success);
}

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)//this method creates a new faculty member for the university
{
  bool foundId = checkDeptExists(fDepId);//checking the variable to see if it exists in the university

  if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<fDepId<<" is a department that does not exist."<<endl;
      return(University::failure);
    }

  Faculty obj(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);//creates an object of the class and pushes the obj with all the information passed to it into the vector
  faculties.push_back(obj);

  return(University::success);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool University::ListCoursesTaughtByFaculty(long facultyId)//this method lists all the courses that are taught by a faculty member using the faculty's Id
{
  bool foundId = checkFacultyExists(facultyId);//checking the variable to see if it exists in the university

  if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<facultyId<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }
  
  for(int i = 0; i < faculties.size(); i++)
    {
      if(facultyId == faculties[i].getsfId())//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
	{
	  cout<<"Listing Courses Taught By A Faculty: "<<endl;
	  cout<<setw(20)<<left<<faculties[i].getsfName()<<setw(20)<<left<<faculties[i].getsfId()<<endl;
	  for(int j = 0; j < courses.size();j++)
	    {
	      if(facultyId == courses[j].getcIsTaughtBy())
		cout<<setw(20)<<left<<courses[j].getcName()<<setw(20)<<left<<courses[i].getcCRN()<<endl;
	    }
	  cout<<endl;
	  return(University::success);
	}
    }
  return(University::failure);
}

bool University::ListCoursesTakenByStudent(long studentId)//this method lists all the courses taken by a student using the student's Id
{
  bool foundId = checkStudentExists(studentId);//checking the variable to see if it exists in the university

  if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<studentId<<" is a student Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < students.size(); i++)
    {
      cout<<"Listing Courses Taken By A Student: "<<endl;
      cout<<setw(20)<<left<<students[i].getsfName()<<setw(20)<<left<<students[i].getsfId()<<endl;
      if(studentId == students[i].getsfId())//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
	{
	  students[i].PrintCourses();
	  return(University::success);
	}
    }
  return(University::failure);
}

bool University::ListFacultiesInDepartment (long departId)//this method lists all the faculty members in a department using the department's Id
{
  bool foundId = checkDeptExists(departId);//checking the variable to see if it exists in the university

  if(foundId == false)
    {
      cout<<departId<<" is a department Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < departments.size(); i++)
    {
      if(departId == departments[i].getdId())
        {
	  cout<<"Listing Faculties in a Department: "<<endl;
	  cout<<setw(20)<<left<<departments[i].getdName()<<setw(20)<<left<<departments[i].getdId()<<endl;
          for(int j = 0; j < faculties.size();j++)
            {
              if(departId == faculties[j].getfDepartId())//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
		cout<<setw(20)<<left<<faculties[j].getsfName()<<setw(20)<<left<<faculties[j].getsfId()<<endl;
            }
          return(University::success);
        }
    }

  return(University::failure);
}

bool University::ListStudentsOfAFaculty(long facultyId)//this method lists the all the students of a faculty member using the faculty memeber's Id
{
  bool foundId = checkFacultyExists(facultyId);//checking the variable to see if it exists in the university

  if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<facultyId<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }
  for(int i = 0; i < faculties.size(); i++)
    {
      if(facultyId == faculties[i].getsfId())
        {
	  cout<<"Listing Students of A Faculty: "<<endl;
          cout<<setw(20)<<left<<faculties[i].getsfName()<<setw(20)<<left<<faculties[i].getsfId()<<endl;
          for(int j = 0; j < students.size(); j++)
            {
              if(facultyId == students[j].getsAdvisorId())
		cout<<setw(20)<<left<<students[j].getsfName()<<students[j].getsfId()<<endl;
            }
	  return(University::success);
        }
    }
  return(University::failure);

}

bool University::ListCoursesOfADepartment(long departId)//this method lists all the courses of a department using the department's Id
{
  bool foundId = checkDeptExists(departId);//checking the variable to see if it exists in the university

  if(foundId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<departId<<" is a department Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < departments.size(); i++)
    {
      if(departId == departments[i].getdId())
        {
          cout<<setw(20)<<left<<departments[i].getdName()<<setw(20)<<left<<departments[i].getdId()<<endl;
          for(int j = 0; j < courses.size();j++)
            {
              if(departId == courses[j].getcDepartId())//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
		cout<<setw(20)<<left<<courses[j].getcName()<<setw(20)<<left<<courses[j].getcCRN()<<endl;
            }
          return(University::success);
        }
    }
  return(University::failure);

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool University::AddACourseForAStudent(long courseId, long stId)//this method adds a course to a student's schedule using the student's Id and the courses' Id
{
  bool foundCId = checkCourseExists(courseId);//checking the variable to see if it exists in the university
  bool foundSId = checkStudentExists(stId);//checking the variable to see if it exists in the university

  if(foundCId == false)
    {
      cout<<courseId<<" is a course Id that does not exist."<<endl;
      return(University::failure);
    }
  if(foundSId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<stId<<" is a student Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < courses.size(); i++)
    {
      if(courseId == courses[i].getcCRN())
        {
          for(int j = 0; j < courses.size(); j++)
            {
	      if(courses[j].getcMaxAvailableSeats() > courses[j].getcAssignedSeats())
		{
		  for(int j = 0; j < students.size(); j++)//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
		    {
		      if(stId == students[j].getsfId())
			{
			  students[j].addACourse(courses[i]);
			  courses[i].incrementAssignedSeats();
			  return(University::success);
			}
		    }
		}
	    }
	  cout<<"The student is already enrolled in this course."<<endl;
	  return(University::failure);
	}
    }

  return(University::failure);
}

bool University::AssignDepartmentChair(long facultyId, long departId)//this method assigns a department chair using the faculty's Id and the department's Id
{
  bool foundDId = checkDeptExists(departId);//checking the variable to see if it exists in the university
  bool foundFId = checkFacultyExists(facultyId);//checking the variable to see if it exists in the university

  if(foundDId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<departId<<" is a department Id that does not exist."<<endl;
      return(University::failure);
    }
  if(foundFId == false)
    {
      cout<<facultyId<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < departments.size(); i++)
    {
      if(departId == departments[i].getdId())
        {
          for(int j = 0; j < departments.size(); j++)
            {
              if(facultyId == departments[j].getdChairId())//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
                {
                  cout<<"This faculty member is already the chair of this department."<<endl;
                  return(University::failure);
                }
            }
          departments[i].setdChairId(facultyId);
          return(University::success);
        }
    }
}

bool University::AssignInstructorToCourse(long facultyId, long courseId)//this method assigns an instructor to a course using the instructor's Id and the course's Id
{
  bool foundCId = checkCourseExists(courseId);//checking the variable to see if it exists in the university
  bool foundFId = checkFacultyExists(facultyId);//checking the variable to see if it exists in the university

  if(foundCId == false)//if the variables are not found then it returns failure and prints an error message
    {
      cout<<courseId<<" is a course Id that does not exist."<<endl;
      return(University::failure);
    }
  if(foundFId == false)
    {
      cout<<facultyId<<" is a faculty Id that does not exist."<<endl;
      return(University::failure);
    }

  for(int i = 0; i < courses.size(); i++)
    {
      if(courseId == courses[i].getcIsTaughtBy())
	{
	  for(int j = 0; j < courses.size(); j++)//for loops, loop through until they are equal to the parameters in the various if statements, then they print out the inforamtion based on those if statement parameters
	    {
	      if(facultyId == courses[j].getcIsTaughtBy())
		{
		  cout<<"This faculty member already teaches this course."<<endl;
		  return(University::failure);
		}
	    }
	  courses[i].setcIsTaughtBy(facultyId);

	  cout<<"Assign Instructor To Course Success"<<endl;
	  return(University::success);
	}
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool University::ListDepartments()//this method lists all the departments in the university
{
  cout<<"Listing Departments"<<endl;

  for(int i = 0; i < departments.size(); i++)//for loop, loops through all of the class vectors and prints out the information in the vectors
    {
      cout<<setw(20)<<left<<departments[i].getdName()<<setw(20)<<left<<departments[i].getdId()<<endl;
    }
}

bool University::ListStudents()//this method lists all the students in the university
{
  cout<<"Listing Students"<<endl;

  for(int i = 0; i < students.size(); i++)//for loop, loops through all of the class vectors and prints out the information in the vectors
    {
      cout<<setw(20)<<left<<students[i].getsfName()<<setw(20)<<left<<students[i].getsfId()<<endl;
    }
}

bool University::ListCourses()//this method lists all the courses in the university
{
  cout<<"Listing Courses"<<endl;
  for(int i = 0; i < courses.size(); i++)//for loop, loops through all of the class vectors and prints out the information in the vectors
    {
      cout<<setw(20)<<left<<courses[i].getcName()<<setw(20)<<left<<courses[i].getcCRN()<<endl;
    }
}

bool University::ListFaculties()//this method lists all the faculty members in the university
{
  cout<<"Listing Faculties"<<endl;
  for(int i = 0; i < faculties.size(); i++)//for loop, loops through all of the class vectors and prints out the information in the vectors
    {
      cout<<setw(20)<<left<<faculties[i].getsfName()<<setw(20)<<left<<faculties[i].getsfId()<<endl;
    }
}

bool University::checkDeptExists(long fDepId)//this method goes through the entire university to check if the department exists
{
  for(int i = 0; i < departments.size(); i++)//for loop, loops through the entire class vector until it finds a match to the variable passed to the function
    {
      if(fDepId == departments[i].getdId())
	return(University::success);
    }
  return(University::failure);
}

bool University::checkFacultyExists(long fDepId)//this method goes through the entire university to check if the faculty member exists
{
  for(int i = 0; i < faculties.size(); i++)//for loop, loops through the entire class vector until it finds a match to the variable passed to the function
    {
      if(fDepId == faculties[i].getsfId())
        return(University::success);
    }
  return(University::failure);
}

bool University::checkCourseExists(long cCRN)//this method goes through the entire university to check if the course exists
{
  for(int i = 0; i < courses.size(); i++)//for loop, loops through the entire class vector until it finds a match to the variable passed to the function
    {
      if(cCRN == courses[i].getcCRN())
        return(University::success);
    }
  return(University::failure);
}

bool University::checkStudentExists(long sStdId)//this method goes through the entire university to check if the student exists
{
  for(int i = 0; i < students.size(); i++)//for loop, loops through the entire class vector until it finds a match to the variable passed to the function
    {
      if(sStdId == students[i].getsfId())
        return(University::success);
    }
  return(University::failure);
}

bool University::checkDeptName(string deptName)//this method goes through the entire university to check if the department name exists
{
  for(int i = 0; i < departments.size(); i++)//for loop, loops through the entire class vector until it finds a match to the variable passed to the function
    {
      if(deptName == departments[i].getdName())
        return(University::success);
    }
  return(University::failure);
}

bool University::ProcessTransactionFile(string fileName)//this method reads in from a transaction file and uses the commands to call other methods of the University class
{
  ifstream fin;//opens the file passed to the function
  fin.open(fileName.data());

  if(!fin)//if the file could not be found it returns failure and an error message
    {
      cout<<"The file could not be opened."<<endl;
      return(University::failure);
    }

  string cmd;

  while(fin>>cmd)//as long as the variable gets information from the file the loops continues
    {
      if(cmd == "CreateNewDepartment")//using the cmd variable, the program selects which command to run and then gathers the input from the file and passes it to all the functions that are necessary
	{
	  string depName, depLoc;
	  long chairId;

	  fin>>depName>>depLoc>>chairId;

	  CreateNewDepartment(depName, depLoc, chairId);
	}
      else if(cmd == "CreateNewFaculty")
	{
	  string name, email, address, dateOfBirth, gender;
	  float salary;
	  int yearsOfExp;
	  long depId;

	  fin>>name>>email>>address>>dateOfBirth>>gender>>salary>>yearsOfExp>>depId;

	  CreateNewFaculty(name, email, address, dateOfBirth, gender, salary, yearsOfExp, depId);
	}
      else if(cmd == "CreateNewCourse")
	{
	  string couName;
	  long deptId, taughtBy;
	  int maxSeats;

	  fin>>couName>>deptId>>taughtBy>>maxSeats;

	  CreateNewCourse(couName, deptId, taughtBy, maxSeats);
	}
      else if(cmd == "CreateNewStudent")
	{
	  string stuName, stuEmail, stuAddress, stuDateOfBirth, stuGender, stuMajor;
	  int stuYearsOfStudy;
	  long stuAdvisorId;

	  fin>>stuName>>stuEmail>>stuAddress>>stuDateOfBirth>>stuGender>>stuYearsOfStudy>>stuMajor>>stuAdvisorId;

	  CreateNewStudent(stuName, stuEmail, stuAddress, stuDateOfBirth, stuGender,  stuYearsOfStudy, stuMajor, stuAdvisorId);
	}
      else if(cmd == "ListDepartments")
	{
	ListDepartments();
	}
      else if(cmd == "ListFaculties")
	{
	ListFaculties();
	}     
      else if(cmd == "ListStudents")
	{
	ListStudents();
	}
      else if(cmd == "ListCourses")
	{
	ListCourses();
	}
      else if(cmd == "ListCoursesOfADepartment")
	{
	  long departId;

	  fin>>departId;

	  ListCoursesOfADepartment(departId);
	}
      else if(cmd == "ListCoursesTaughtByFaculty")
	{
	  long facultyId;

	  fin>>facultyId;

	  ListCoursesTaughtByFaculty(facultyId);
	}
      else if(cmd == "ListCoursesTakenByStudent")
	{
	  long stdId;

	  fin>>stdId;

	  ListCoursesTakenByStudent(stdId);
	}
      else if(cmd == "ListFacultiesInDepartment")
	{
	  long departmentId;

	  fin>>departmentId;

	  ListFacultiesInDepartment(departmentId);
	}
      else if(cmd == "ListStudentsOfAFaculty")
	{
	  long facId;

	  fin>>facId;

	  ListStudentsOfAFaculty(facId);
	}
      else if(cmd == "AssignDepartmentChair")
	{
	  long faculId, dId;

	  fin>>faculId>>dId;

	  AssignDepartmentChair(faculId, dId);
	}
      else if(cmd == "AssignInstructorToCourse")
	{
	  long faId, cId;

	  fin>>faId>>cId;

	  AssignInstructorToCourse(faId, cId);
	}
      else if(cmd == "AddACourseForAStudent")
	{
	  long coId, sId;

	  fin>>coId>>sId;

	  AddACourseForAStudent(coId, sId);
	}
    }
}

