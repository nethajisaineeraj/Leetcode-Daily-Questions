// 1912 Design Movie Rental System

struct PairComparator
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

struct PairEqual
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.first == b.first && a.second == b.second;
    }
};

class MovieRentingSystem
{
public:
    unordered_map<int, multiset<pair<int, int>, PairComparator>> m_ps;
    unordered_map<pair<int, int>, int, PairHash, PairEqual> sm_p;
    set<tuple<int, int, int>> rented; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &entry : entries)
        {
            m_ps[entry[1]].insert({entry[2], entry[0]});
            sm_p[{entry[0], entry[1]}] = entry[2];
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;
        int count = 0;
        for (auto &ps : m_ps[movie])
        {
            if (count == 5)
                break;
            // check if rented
            if (rented.count({ps.first, ps.second, movie}) == 0)
            {
                result.push_back(ps.second);
                count++;
            }
        }
        return result;
    }

    void rent(int shop, int movie)
    {
        int price = sm_p[{shop, movie}];
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = sm_p[{shop, movie}];
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;
        int count = 0;
        for (auto &[price, shop, movie] : rented)
        {
            if (count == 5)
                break;
            result.push_back({shop, movie});
            count++;
        }
        return result;
    }
};
