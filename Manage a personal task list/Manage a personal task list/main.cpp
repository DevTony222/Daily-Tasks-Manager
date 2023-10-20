#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task completed: " << tasks[index].description << std::endl;
        }
        else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void displayTasks() {
        std::cout << "Task List:" << std::endl;
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;

    taskManager.addTask("Finish coding project");
    taskManager.addTask("Buy groceries");
    taskManager.addTask("Call mom");

    taskManager.displayTasks();

    taskManager.completeTask(1);

    taskManager.displayTasks();

    return 0;
}