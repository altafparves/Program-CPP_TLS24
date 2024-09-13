#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

// Display menu
void menu()
{
    cout << "\n--- To-Do List ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Out\n";
    cout << "Select an option: ";
}

// get current time as string function
string getCurrentTime()
{
    time_t currentTime = time(0);   // get current time
    char *dt = ctime(&currentTime); // convert current time to string
    return string(dt);
}

int main()
{
    vector<string> todoList; // save the list of tasks
    vector<string> timeList; // save the time when the task is added
    int choice;

    do
    {
        menu();
        cin >> choice;
        cin.ignore(); // Mengabaikan newline setelah input

        switch (choice)
        {
        // add task
        case 1:
        {
            string task;
            cout << "Add New Task: ";
            getline(cin, task);
            todoList.push_back(task);             // ADD task to vector
            timeList.push_back(getCurrentTime()); // Add current time to vector
            cout << "Task Successfully added!\n";
            break;
        }
        // view task
        case 2:
        {
            if (todoList.empty())
            {
                cout << "Task list is empty\n";
            }
            else
            {
                cout << "\nTask List:\n";
                for (size_t i = 0; i < todoList.size(); ++i)
                {

                    cout << i + 1 << ". " << todoList[i] << " (Added on: " << timeList[i] << ")\n";
                }
            }
            break;
        }
        // delete task
        case 3:
        {
            if (todoList.empty())
            {
                cout << "No tasks to delete.\n";
            }
            else
            {
                int index;
                cout << " Enter the task number to delete : ";
                cin >>
                    index;
                if (index > 0 && index <= todoList.size())
                {
                    todoList.erase(todoList.begin() + index - 1); // delete task from vector with index
                    timeList.erase(timeList.begin() + index - 1);
                    cout << "Task deleted successfully!\n";
                }
                else
                {
                    cout << "Invalid Task Number\n";
                }
            }
            break;
        }
        // exit
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
