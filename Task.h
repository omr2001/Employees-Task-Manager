#pragma once
#include <string>
using namespace std;
#define MAX_discription_LEN 1000

class Task
{
public:
	string task_title;
	char discription[MAX_discription_LEN];
	string Asigndate;
	string endingDate;
	string empName;
	int priority;


	bool operator < (const Task& rhs) const { return priority < rhs.priority; }
	bool operator > (const Task& rhs) const { return priority > rhs.priority; }


	void read();
	bool isValidName(const string& input);
	bool isValidPriority(int priority);

};
