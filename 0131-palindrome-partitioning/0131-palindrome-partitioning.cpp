class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, isPal, path, res);
        return res;
    }

private:
    void dfs(int start, const string& s, const vector<vector<bool>>& isPal,
             vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPal[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(end + 1, s, isPal, path, res);
                path.pop_back();  
            }
        }
    }
};