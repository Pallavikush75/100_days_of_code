class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(currMax, currMin); // flip
            
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            
            result = max(result, currMax);
        }
        
        return result;
    }
};
