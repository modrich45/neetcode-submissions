class Solution {
   public:
    int findRow(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int ans = -1;
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[mid][0] <= target) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1;
        int x = findRow(matrix, target);
        if(x==-1) return false;
        if (search(matrix[x], target) != -1) {
            return true;
        }
        return false;
    }
};
