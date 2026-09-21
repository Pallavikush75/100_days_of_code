class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz"};

        string current;
        backtrack(0, digits, mp, current, result);
        return result;
    }

private:
    void backtrack(int idx, const string& digits, const vector<string>& mp,
                   string& current, vector<string>& result) {
        if (idx == digits.size()) {
            result.push_back(current);
            return;
        }

        for (char c : mp[digits[idx] - '0']) {
            current.push_back(c);
            backtrack(idx + 1, digits, mp, current, result);
            current.pop_back();
        }
    }
};