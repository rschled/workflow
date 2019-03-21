#include "Skillset.h"
#include "Employee.h"
#include <algorithm>

using namespace std;
//might rewrite but still useful code to have
Skillset::Skillset(vector<Employee> Employees_in)
{
	for (vector<Employee>::iterator emp = Employees_in.begin();
		emp != Employees_in.end(); emp++)
	{
		for (vector<string>::iterator s_iter = (emp->get_skills()).begin();
			s_iter != (emp->get_skills()).end(); s_iter++)
		{
			if (find(Company_skills.begin(), Company_skills.end(), *s_iter)
				!= Company_skills.end())
			{
				Company_skills.push_back(*s_iter);
				vector<Employee> retEmp;
				retEmp.push_back(*emp);
				for (vector<Employee>::iterator other_emp = emp + 1;
					other_emp != Employees_in.end(); other_emp++)
				{
					vector<string>::iterator s_iter2 = (other_emp->get_skills()).begin();
					while (*s_iter != *s_iter2 && s_iter2 != (other_emp->get_skills()).end())
					{
						*s_iter2++;
					}
					if (*s_iter == *s_iter2)
					{
						retEmp.push_back(*other_emp);
					}

				}
				Qualified_Employees.push_back(retEmp);
			}
		}
	}
}
void Skillset::remove_company_skill(string skill_name)
{
	int index = 0;
	for (vector<string>::iterator s_iter = Company_skills.begin(); s_iter
		!= Company_skills.end(); s_iter++)
	{
		if (*s_iter == skill_name)
		{
			Company_skills.erase(s_iter);
			Qualified_Employees.erase(Qualified_Employees.begin() +  index);
		}
		index++;
	}
}
void Skillset::add_company_skill(string skill_name)
{
	Company_skills.push_back(skill_name);
	vector<Employee> ret;
	Qualified_Employees[Company_skills.size() - 1].push_back(ret);
}
void Skillset::add_employee(string skill_name, Employee employee_name)
{
	int index = 0;
	for (vector<string>::iterator iter = Company_skills.begin();
		iter != Company_skills.end(); iter++)
	{
		if (*iter == skill_name)
		{
			Qualified_Employees[index].push_back(employee_name);
		}
		index++;
	}
}
void Skillset::remove_employee(string skill_name, Employee * employee_name)
{
	int index = 0;
	for (vector<string>::iterator iter = Company_skills.begin();
		iter != Company_skills.end(); iter++)
	{
		if (*iter == skill_name)
		{
			for (vector<Employee>::iterator emp = Qualified_Employees[index].begin();
				emp != Qualified_Employees[index].end(); emp++)
			{
				if (*emp == *employee_name)
				{
					Qualified_Employees[index].erase(emp);
				}
			}
			Qualified_Employees[index].push_back(*employee_name);
		}
		index++;
	}
}
Employee * Skillset::get_available_employee(string skill_name)
{
	int index = 0;
	for (vector<string>::iterator iter = Company_skills.begin();
		iter != Company_skills.end(); iter++)
	{
		if (*iter == skill_name)
		{
			for (vector<Employee>::iterator emp = Qualified_Employees[index].begin();
				emp != Qualified_Employees[index].end(); emp++)
			{
				if (!emp->is_busy())
				{
					Employee * ret = &(*emp);
					return ret;
				}
			}
		}
		index++;
	}
}
bool operator==(Employee emp1, Employee emp2)
{
	if (emp1.get_name() == emp2.get_name() && emp1.get_ID() == emp2.get_ID())
	{
		return true;
	}
	return false;
}