class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        premutation(nums, 0, result);
        return result;
    }
    void premutation(vector<int>& nums, int s, vector<vector<int> > &result) {
    	if(s >= nums.size()) {
    		result.push_back(nums);
    		return;
    	}
    	for(int i = s; i < nums.size(); i++) {
    		if(nums[s] == nums[i])
    			continue;
    		swap(nums[s], nums[i]);
    		premutation(nums, s+1, result);
    		swap(nums[s], nums[i]);
    	}
    }
};