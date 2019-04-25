#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int> > ans;
	if(nums.size() < 4)
		return ans;
	
	sort(nums.begin(), nums.end());
	int size = nums.size();
	for(int i =  0; i < size - 3; i++) {
		for(int j = i+1; j < size - 2; j++) {
			int k = j + 1;
			int l = size - 1;
			while(k < l) {
				int tmp = nums[i] + nums[j] + nums[k] + nums[l];
				if(tmp > target)
					l--;
				else if(tmp < target)
					k++;
				else {
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[k]);
					v.push_back(nums[l]);
					ans.push_back(v);
					while(k < l && nums[k] == v[2]) k++;
					while(k < l && nums[l] == v[3]) l--;
				}
			}
			while(j + 1 < size && nums[j+1] == nums[j]) j++;
		}
		while(i + 1 < size && nums[i+1] == nums[i]) i++;
	}
	return ans;
}
int main() {

}