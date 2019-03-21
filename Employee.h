#ifndef SKILLS_H
#define SKILLS_H

#include <string>
#include <vector>
using namespace std;

class Employee
{
	
public:
	Employee();
	Employee(string in_name, vector<string> in_skill, int in_id);
	bool is_busy();
	void set_busy(bool work);
	string get_name();
	int get_ID();
	void add_skill(const string new_skill);
	void remove_skill(const string new_skill);
	vector<string> get_skills();
	


private:
	bool busy;
	vector<string> Employee_skills;
	string name;
	int Employee_ID;
};
//Class Employee
	//----Public-----
		//ctor
		//add Skill
		//bool is_busy
	//----Private----
		//vector skills
		//String Name
		//Employee ID ??
		//bool busy


#endif //Employee
