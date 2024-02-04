#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    // Add a new task to the list
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // View all tasks with their status
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (const auto& task : tasks) {
                cout << "- " << task.description;
                if (task.completed) {
                    cout << " (Completed)";
                }
                cout << endl;
            }
        }
    }

    // Mark a task as completed
    void markAsCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // Remove a task from the list
    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;
    char choice;

    do {
        cout << "\n===== Todo List Manager =====" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case '4': {
                int taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case '5':
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != '5');

    return 0;
}
