class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }

    void solve(string& s, int start, vector<string>& path) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (!isPalindrome(s, start, end))
                continue;

            path.push_back(s.substr(start, end - start + 1));

            solve(s, end + 1, path);

            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);
        return res;
    }
};