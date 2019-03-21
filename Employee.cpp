#include "Employee.h"

using namespace std;

//Default ctor
Employee::Employee()
	:busy(false), name("temp"){ }

//Standard ctor
Employee::Employee(string in_name, vector<string> in_skill, int in_id)
	:busy(false), name(in_name), Employee_skills(in_skill), Employee_ID(in_id) { }

//busy getter
bool Employee::is_busy()
{
	return busy;
}

//busy setter
void Employee::set_busy(bool work)
{
	busy = work;
}

//name getter
string Employee::get_name()
{
	return name;
}

//ID getter
int Employee::get_ID()
{
	return Employee_ID;
}

//add skill to skill vector and update search data
void Employee::add_skill(const string new_skill)
{
	Employee_skills.push_back(new_skill);
}

//requires skill is a valid string in the skils vector
//reomve skill from skill vector and update search data
void Employee::remove_skill(const string new_skill)
{
	vector<string>::iterator iter = Employee_skills.begin();
	while (*iter != new_skill && iter != Employee_skills.end())
	{
		iter++;
	}
	if (*iter != new_skill)
	{
		Employee_skills.erase(iter);
	}
}
vector<string> Employee::get_skills()
{
	return Employee_skills;
}