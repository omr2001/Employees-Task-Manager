#include "Task.h"
#include <iostream>
#include <string>

using namespace std;
void Task::read()
{
	cout << "Task title : ";
	cin >> task_title;
	cout << "Enter the Discription of the task (press # to complete) : ";
	cin.getline(discription, MAX_discription_LEN, '#');
	cout << "Assigning date : ";
	cin >> Asigndate;
	cout << "Ending date : ";
	cin >> endingDate;
	cout << "Employee name : ";
	cin >> empName;
	while (!isValidName(empName))
	{
		cout << " Invalid name !! Enter The Employee's Name again " << endl;
		cout << "Must be [A : Z ] OR [ a : z ] OR [ space ]" << endl;
		cin >> empName;
	}
	cout << "Enter The Priority of the Task : ";
	cin >> priority;
	while (!isValidPriority(priority))
	{
		cout << " Invalid number !! Enter The Priority again " << endl;
		cout << "Must be [ 1:10 ]" << endl;
		cin >> priority;
	}
}
bool Task::isValidName(const string& input) {
	for (int i = 0; i < input.length(); i++)
	{
		if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || input[i] == ' ')) {
			return false;
		}
	}
	return true;
}

bool Task::isValidPriority(int priority) {
	if (priority < 1 || priority > 10) {
		return false;
	}
	else {
		return true;
	}
}