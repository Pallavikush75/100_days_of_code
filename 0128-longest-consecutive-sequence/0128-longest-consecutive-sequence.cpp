class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int cur = num;
                int len = 1;

                while (st.find(cur + 1) != st.end()) {
                    cur++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};