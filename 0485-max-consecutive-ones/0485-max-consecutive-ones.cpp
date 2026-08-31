class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;   
        int currCount = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currCount++;                 
                maxCount = max(maxCount, currCount); 
            } else {
                currCount = 0;              
            }
        }

        return maxCount;
    }
};
