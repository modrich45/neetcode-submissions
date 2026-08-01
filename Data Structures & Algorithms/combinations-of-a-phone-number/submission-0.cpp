class Solution {
   public:
    vector<string> ans;

    vector<vector<char>> key = {{},
                                {},
                                {'a', 'b', 'c'},
                                {'d', 'e', 'f'},
                                {'g', 'h', 'i'},
                                {'j', 'k', 'l'},
                                {'m', 'n', 'o'},
                                {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'},
                                {'w', 'x', 'y', 'z'}};

    void solve(string digits, string temp, int i) {
        if (i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        if (i > digits.size()) {
            return;
        }

        int x = (int)digits[i] - '0';

        for (char c : key[x]) {
            temp.push_back(c);
            solve(digits, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        solve(digits, "", 0);

        return ans;
    }
};