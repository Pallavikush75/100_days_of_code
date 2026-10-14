class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k,
                   vector<int>& current, vector<vector<int>>& result) {
        if ((int)current.size() == k) {
            result.push_back(current);
            return;
        }

        int need = k - current.size();
        for (int i = start; i <= n - need + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back(); 
        }
    }
};