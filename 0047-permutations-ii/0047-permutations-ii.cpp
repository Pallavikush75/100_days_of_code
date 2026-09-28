class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used,
                   vector<vector<int>>& result) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used, result);
            curr.pop_back();
            used[i] = false;
        }
    }
};