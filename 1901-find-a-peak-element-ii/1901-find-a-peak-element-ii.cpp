class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int midCol = left + (right - left) / 2;
            
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            int left_val = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int right_val = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;
            
            if (mat[maxRow][midCol] > left_val && mat[maxRow][midCol] > right_val) {
                return {maxRow, midCol};
            } else if (left_val > mat[maxRow][midCol]) {
                right = midCol - 1;  
            } else {
                left = midCol + 1;   
            }
        }
        
        return {-1, -1};  
    }
};