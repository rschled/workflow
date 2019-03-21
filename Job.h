#ifndef JOB_H
#define JOB_H

#include <string>
#include <vector>
using namespace std;
class Job
{
public:
	Job();
	add_prereq(string name);
	remove_prereq(string name);
private:
	vector<string> prereqs;
	vector<string> postreqs;
	string skill;
};

#endif