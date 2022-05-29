#include<iostream>
#include<functional>
#include<set>
#include<vector>
#include<string>
#include<conio.h>
#include<cstdlib>
#include"Task.h"
using namespace std;
Task t;
multiset <Task, greater<>> task_manager;
void Read_data()
{
	t.read();
	task_manager.insert(t);
}
void Display_tasks()
{
	if (task_manager.empty() == true)
	{
		cout << "No Tasks was Added" << endl;
	}
	else {
		for (const auto & e : task_manager)
		{
			cout << "Employee Name: " << e.empName << "\n"
				<< "Priorty : "<<e.priority << "\n"
				<< "Task Title : " << e.task_title << "\n"
				<< "Assigning date : " << e.Asigndate << "\n"
				<< "Ending date : " << e.endingDate << "\n"
				<< "The Discription of The Task "<<e.discription << "\n";
			cout << "---------------------------" << endl;
		}
	}
}
void Mark_Task()
{
	if (task_manager.empty())
	{
		cout << "No Tasks Added to be Finished" << endl;
	}
	else
	{
		multiset<Task, greater<int>>::iterator itr;
		itr = task_manager.begin();
		task_manager.erase(itr);
		itr = task_manager.begin();
		if (task_manager.empty())
		{
			cout << "Many will start Fast, Few will Finish Strong" << endl;
			cout << "Gary Ryan Blair" << endl;
		}

		else
		{
			cout << "Remainder : The Next Task is " << endl;
			cout << "The Task Title is " << itr->task_title << endl;
			cout << "The Task Priorty is " << itr->priority << endl;
			cout << "The Employee Name is  " << itr->empName << endl;
			cout << "The Ending Date is " << itr->endingDate << endl;
			cout << "The Assigning Date is " << itr->Asigndate << endl;
		}
	}
}
void Edit()
{
	if (task_manager.empty())
	{
		cout << "No Tasks To Edit:-\n";
	}
	else
	{
		string TN;
		cout << "Enter Task Name To Edit: ";
		cin >> TN;
		multiset<Task, greater<int>>::iterator itr;
		Task TaskFound;
		int NewPriorty;
		cout << "Enter New Priorty: ";
		cin >> NewPriorty;
		for (itr = task_manager.begin(); itr != task_manager.end(); itr++)
		{
			if (TN == itr->task_title)
			{
				TaskFound.empName = itr->empName;
				TaskFound.Asigndate = itr->Asigndate;
				TaskFound.endingDate = itr->endingDate;
				TaskFound.priority = NewPriorty;
				TaskFound.task_title = itr->task_title;
				strcpy_s(TaskFound.discription, itr->discription);
				task_manager.erase(itr);
				task_manager.insert(TaskFound);
				break;
			}
		}
	}
}
void Require_Enter()
{
	cout << "Click Enter To Continue" << endl;
	while (getch() != 13);
}
int main()
{
	char choice = 'a';
	cout << "---------------------The Task Manager-----------------" << endl;

	while (choice != '5')
	{
		cout << "Press 1 to Insert new Task:-" << endl;
		cout << "Press 2 to Display The Tasks:-" << endl;
		cout << "Press 3 If you have finished The Most Priortized Task:-" << endl;
		cout << "Press 4 to Edit a Task's Priorty:-" << endl;
		cout << "Press 5 to Exit:-" << endl;
		choice = getch();
		cout << "You have Clicked " << choice << endl;
		cout << "-------------------------------------------------\n";
		if (choice == '1')
		{
			Read_data();
		}
		if (choice == '2')
		{
			Display_tasks();
		}
		if (choice == '3')
		{
			Mark_Task();
		}
		if (choice == '4')
		{
			Edit();
		}
		Require_Enter();
		system("cls");
		cout << "---------------------The Task Manager----------------------\n";
	}
	system("pause");
	return 0;
}