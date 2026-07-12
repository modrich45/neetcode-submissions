class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {}

    void set(string key, string value, int timestamp) { m[key].push_back({value, timestamp}); }

    string get(string key, int timestamp) {
        vector<pair<string, int>> temp = m[key];
        int i = 0, j = temp.size() - 1;
        int idx = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (temp[mid].second <= timestamp) {
                idx = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        if (idx == -1) return "";

        return temp[idx].first;
    }
};
