class Solution {
public:
	inline void swap(int& a, int& b) {
		int tmp =  a;
		a = b;
		b = tmp;
	}
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = nums.size() - 1;
        while(w <= b) {
        	if(nums[w] == 0) {
        		swap(nums[r], nums[w]);
        		w++;
        		r++;
        	} else if(nums[w] == 1) {
        		w++;
        	} else if(nums[w] == 2) {
        		swap(nums[w], nums[b]);
        		b--;
        	}
        }
    }
};