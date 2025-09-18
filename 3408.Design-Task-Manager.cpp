#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    struct TaskComparator {
        bool operator()(const Task& lhs, const Task& rhs) const {
            if (lhs.priority != rhs.priority) {
                return lhs.priority > rhs.priority; 
            }
            return lhs.taskId > rhs.taskId;  
        }
    };
    set<Task, TaskComparator> userTasks;
    unordered_map<int, pair<int, int>> taskIdToUser;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int>& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            userTasks.insert(Task{priority, taskId, userId});
            taskIdToUser[taskId] = {userId, priority};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userTasks.insert(Task{priority, taskId, userId});
        taskIdToUser[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, priority] = taskIdToUser[taskId];
        userTasks.erase(Task{priority, taskId, userId});
        userTasks.insert(Task{newPriority, taskId, userId});
        taskIdToUser[taskId] = {userId, newPriority};
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = taskIdToUser[taskId];
        userTasks.erase(Task{priority, taskId, userId});
        taskIdToUser.erase(taskId);
    }
    
    int execTop() {
        if (userTasks.empty()) return -1;
        Task task = *userTasks.begin();
        userTasks.erase(task);
        taskIdToUser.erase(task.taskId);
        return task.userId;
    }
};

int main() {
    vector<vector<int>> tasks = {{1, 101, 8}, {2, 102, 20}, {3, 103, 5}};
    TaskManager* taskManager = new TaskManager(tasks);
    taskManager->add(4, 104, 5); 
    taskManager->edit(102, 8); 
    cout << taskManager->execTop() << endl; // 2
    taskManager->rmv(101);
    taskManager->add(50, 101, 8); 
    cout << taskManager->execTop() << endl; // 50
} 