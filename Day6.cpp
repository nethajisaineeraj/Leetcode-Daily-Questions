// 3508 Implement Router
class Router
{
public:
    unordered_map<int, deque<int>> destTimestamps;
    unordered_set<long long> oldPackets;
    queue<vector<int>> q;
    int memoryLimit;

    long long hashFunc(int source, int destination, int timestamp)
    {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    Router(int memoryLimit)
    {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        long long key = hashFunc(source, destination, timestamp);
        if (oldPackets.find(key) == oldPackets.end())
        {
            if (q.size() == memoryLimit)
                forwardPacket();
            q.push({source, destination, timestamp});
            oldPackets.insert(key);
            destTimestamps[destination].push_back(timestamp);
            return true;
        }
        return false;
    }

    vector<int> forwardPacket()
    {
        if (q.size() != 0)
        {
            vector<int> frontPacket = q.front();
            q.pop();
            long long key = hashFunc(frontPacket[0], frontPacket[1], frontPacket[2]);
            oldPackets.erase(key);
            destTimestamps[frontPacket[1]].pop_front();
            return frontPacket;
        }
        return vector<int>();
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto it1 = lower_bound(destTimestamps[destination].begin(), destTimestamps[destination].end(), startTime);
        auto it2 = upper_bound(destTimestamps[destination].begin(), destTimestamps[destination].end(), endTime);
        int start = 0, end = 0;
        if (it1 != destTimestamps[destination].end())
        {
            start = it1 - destTimestamps[destination].begin();
        }
        else
        {
            start = destTimestamps[destination].size();
        }
        if (it2 != destTimestamps[destination].begin())
        {
            end = it2 - destTimestamps[destination].begin() - 1;
        }
        else
        {
            end = -1;
        }
        if (start <= end)
            return end - start + 1;
        return 0;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */