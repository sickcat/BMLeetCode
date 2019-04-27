class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> t(nums.size(), 0);
        int max = nums[0];
        t[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
        	t[i] = nums[i] + (t[i - 1] < 0 ? 0 : t[i - 1]);
        	max = max < t[i] ? t[i] : max;
        }
        return max;
    }
};