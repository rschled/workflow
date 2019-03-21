#ifndef SKILLSET_H
#define SKILLSET_H

#include <string>
#include <vector>
#include "Employee.h"

using namespace std;
//Goal -> build skills database
//Define new Skills ADT
//------Structure---------
	//Top level Database
	//contains employee data types
	//employee data type contains skills 
	//employee automatically updates skills with pointer 
	//skill data type?

//------Functions---------
	//Add employee
	//Add skill
	//overload [][] - [skill][employee*] 
	
//------Variables----------
	//vector/array of employees ADT
	//Skill name - row 2 contains vector with *Employee
	//
class Skillset
{
public:
	Skillset(vector<Employee> Employees_in);
	void remove_company_skill(string skill_name);
	void add_company_skill(string skill_name);
	void add_employee(string skill_name, Employee employee_name);
	void remove_employee(string skill_name, Employee * employee_name);
	Employee * get_available_employee(string skill_name);
	//operator [][]
private:
	vector<string> Company_skills;
	vector<vector<Employee>> Qualified_Employees;

};
#endif //Skillset
