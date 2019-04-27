class Solution {
public:
    bool canJump(vector<int>& nums) {
    	// max index to reach
    	int max = nums[0];
    	int i = 0;
        for(; i <= max; i++)
        	if(max >= nums.size())
        		return true;
        	else if (i + nums[i] > max)
        		max = i+nums[i];
    	return i == (nums.size());
    }
};