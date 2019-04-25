#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int i = nums.size() - 1;
        for(; i > 0; i--)
        	if(nums[i] <= nums[i-1])
        		continue;
        	else
        		break;
        if (i <= 0) {
        	reverse(nums.begin(), nums.end());
        } else {
        	int l = nums.size() - 1;
        	for(; l >= i; l--)
        		if(nums[l] > nums[i-1])
        			break;
        	swap(nums[i-1], nums[l]);
        	reverse(nums.begin() + i, nums.end());
        }

    }
};
int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(1);
	Solution a;
	a.nextPermutation(v);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}