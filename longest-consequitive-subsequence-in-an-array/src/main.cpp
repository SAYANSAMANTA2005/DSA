class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, lis[i]);
        }
        
        return maxi;
    }
};