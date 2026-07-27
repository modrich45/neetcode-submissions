class Solution {
   public:
    int leastInterval(vector<char>& tasks, int k) {
        unordered_map<char, int> m;
        multiset<pair<int, char>> ms;
        queue<pair<int, pair<int, char>>> q;
        int ans = 0;
        int n = tasks.size();
        int cnt = (n * k) + 3;
        for (int i = 0; i < n; i++) {
            m[tasks[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            ms.insert({it->second, it->first});
        }
        int x = 1;
        while (x <= cnt) {
            if (!ms.empty()) {
                auto it = prev(ms.end());
                if ((*it).first > 1) {
                    q.push({x, {(*it).first - 1, (*it).second}});
                }
                ms.erase(it);
            }
            if (x - q.front().first == k) {
                ms.insert(q.front().second);
                q.pop();
            }
            if (q.empty() && ms.empty()) {
                return x;
            }
            x++;
        }
        return -1;
    }
};
