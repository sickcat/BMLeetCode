class Solution {
public:
    string getPermutation(int n, int k) {
    	int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    	string ans;
    	string nums = "123456789";
    	k--;
    	for(int i = n; i >= 1; i--) {
    		int j = k/f[i-1];
    		k = k%f[i-1];
    		ans += nums[j];
    		nums.erase(nums.begin() + j);
    	}
    	return ans;
    }
};