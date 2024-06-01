/*
TASK 4
To-DO-LIST
Build a simple console-based to-do list manager that allows users to add, view, and delete tasks
    Task Input              :  Allow users to input tasks they want to add to the list.
    Add Task                :  Implement a function to add tasks to the list.
    View Tasks              :  Display the list of tasks with their status (completed or pending).
    Mark Task as Completed  :  Allow users to mark tasks as completed.
    Remove Task             :  Provide an option to remove tasks from the list.
*/
#include <iostream>
#include <vector>
#include <utility> //For pair
using namespace std;

void addTask(vector<pair<string, bool>> &vp)
{
    string task;
    cout << "Enter the task to add to the list:-\t";
    cin.ignore();
    getline(cin, task);
    vp.push_back({task, false});
}

void Display(vector<pair<string, bool>> &vp)
{
    if (vp.size() == 0)
    {
        cout << "-----NO ANY TASK TO DISPLAY-----\n\n";
        return;
    }
    cout << "\nDisplaying the tasks:-\n";
    for (int i = 0; i < vp.size(); i++)
    {
        cout << "TASK " << i + 1 << ": " << vp[i].first << "\n";
        cout << "Status: ";
        if (vp[i].second)
            cout << "Completed\n\n";
        else
            cout << "Pending\n\n";
    }
}

void markAsCompleted(vector<pair<string, bool>> &vp)
{
    if (vp.size() == 0)
    {
        cout << "-----NO ANY TASK TO MARK AS COMPLETED-----\n\n";
        return;
    }
    Display(vp);
    int index;
    cout << "Enter the serial number of the task to mark as completed:- ";
    cin >> index;
    for (int i = 0; i < vp.size(); i++)
    {
        if (index - 1 == i)
        {
            if (vp[i].second)
            {
                cout << "Already marked as completed\n";
                return;
            }
            vp[i].second = true;
            cout << index << ": this task is marked as completed\n";
            return;
        }
    }
    cout << "-----WRONG TASK NUMBER-----\n";
}

void remove(vector<pair<string, bool>> &vp)
{
    if (vp.size() == 0)
    {
        cout << "-----NO ANY TASK TO REMOVE-----\n\n";
        return;
    }
    Display(vp);
    int index;
    cout << "Enter the serial number of the task to remove:- ";
    cin >> index;
    if (index > vp.size())
    {
        cout << "-----WRONG TASK NUMBER-----\n";
        return;
    }
    vp.erase(vp.begin() + index - 1);
    cout << index << ": this task is removed\n";
}

void ToDoList()
{
    vector<pair<string, bool>> vp;
    bool flag = false;
    while (1)
    {
        int input;
        cout << "Enter 1: To add task to the list\n";
        cout << "Enter 2: To display all the tasks with their status (completed or pending)\n";
        cout << "Enter 3: To mark a task as completed\n";
        cout << "Enter 4: To remove a task from the list\n";
        cout << "Enter 5: Exit\n";
        cout << "Enter from above MENU:- ";
        cin >> input;
        switch (input)
        {
        case 1:
            addTask(vp);
            break;
        case 2:
            Display(vp);
            break;
        case 3:
            markAsCompleted(vp);
            break;
        case 4:
            remove(vp);
            break;
        case 5:
            flag = true;
            break;
        default:
            cout << "-----INVALID CHOICE-----\nPlease Choose Again\n\n";
            break;
        }
        if (flag)
        {
            cout << "\n-----Thank You For Using To-Do-List-----\n";
            break;
        }
    }
}

int main()
{
    cout << "\n----------Welcome to your TO-DO-LIST----------\n";
    ToDoList();
    return 0;
}