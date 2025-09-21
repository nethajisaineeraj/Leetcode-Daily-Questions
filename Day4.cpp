// 3408 Design Task Manager

struct Cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

class TaskManager
{
public:
    unordered_map<int, int> task_priority;
    unordered_map<int, int> task_user;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> maxHeap;

    // - - - *userId*    0
    // - - - *taskId*    1
    // - - - *priority*  2

    TaskManager(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];
            task_priority[taskId] = priority;
            task_user[taskId] = userId;
            maxHeap.push({taskId, priority});
        }
    }

    void add(int userId, int taskId, int priority)
    {
        task_priority[taskId] = priority;
        task_user[taskId] = userId;
        maxHeap.push({taskId, priority});
    }

    void edit(int taskId, int newPriority)
    {
        task_priority[taskId] = newPriority;
        int userId = task_user[taskId];
        maxHeap.push({taskId, newPriority});
    }

    void rmv(int taskId)
    {
        task_priority.erase(taskId);
        task_user.erase(taskId);
    }

    int execTop()
    {
        while (!maxHeap.empty())
        {
            auto [taskId, priority] = maxHeap.top();
            if (task_priority.count(taskId) && task_priority[taskId] == priority)
            {
                // valid
                maxHeap.pop();
                int userId = task_user[taskId];
                task_priority.erase(taskId);
                task_user.erase(taskId);
                return userId;
            }
            maxHeap.pop(); // discard stale
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */