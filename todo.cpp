#include <iostream>
#include <vector>
#include <string>

using namespace std;

// task structure of the to-do list
struct task {
    int id;
    string description;
    string note;
    bool completed;
};

// class to manage the to-do list
class todoList {
private:
    vector<task> tasks;
    int nextId;

public:
    todoList() : nextId(1) {}

    void addtask(const string& description) {
        tasks.push_back({ nextId++, description, "", false });
    }

    void removetask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                break;
            }
        }
    }

    void completetask(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                break;
            }
        }
    }

    void addDescription(int id, const string& description, const string& note) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.description = description;
                task.note = note;
                break;
            }
        }
    }

    void listtasks() const
     {
        for (const auto& task : tasks) {
            cout << (task.completed ? "[*] " : "[ ] ") << task.id << ": " << task.description << endl;
            if (!task.note.empty()) {
                cout <<   "Note: " << task.note << endl;
            }
        }
    }
};

// Function to show menu
void showMenu() {
    cout<<"======================================="<<endl;
    cout<<"wel-come to to-do list"<<endl;
    cout<<"======================================="<<endl;
    cout<<"here your choices^-^"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout << "1. Add task"<<endl;
    cout << "2. Add description and note to a task" << endl;
    cout << "3. Remove task" << endl;
    cout << "4. Complete task" << endl;
    cout << "5. List tasks" << endl;
    cout << "6. Exit" << endl;
}

// Function to get task description and note from user
void gettaskDetails(string& description, string& note) {
    cout << "Enter task description: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, description);
    cout << "what i want to do to fullfill my task: ";
    getline(cin, note);
    cout<<"all the best!"<<endl;
}

int main() {
    todoList todoList;
    int choice, id;
    string description, note;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
         {
            case 1:
                cout << "Enter  task: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, description);
                todoList.addtask(description);
                cout<<" Task successfully added"<<endl;
                break;
            case 2:
                cout << "Enter task ID to add description and note: ";
                cin >> id;
                gettaskDetails(description, note);
                todoList.addDescription(id, description, note);
                cout<<" Task description successfully added"<<endl;
                break;
            case 3:
                cout << "Enter task ID to remove:";
                cin >> id;
                todoList.removetask(id);
                cout<<" Task deleted successfully"<<endl;
                break;
            case 4:
                cout << "enter task ID to complete: ";
                cin >> id;
                todoList.completetask(id);
                cout<<"congratulations!!! you have successfully completed your task"<<endl;
                break;
            case 5:
                cout<<" here is your task list->"<<endl;
                todoList.listtasks();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
