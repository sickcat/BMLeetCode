#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;
        while(l <= r) {
            // cout << l << ":" << r << endl;
            int mid = (l + r)/2;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[l] != target)
                l = mid;
            else if(nums[r] != target)
                r = mid;
            else if(l > 0 && nums[l-1] == target)
                l--;
            else if(r + 1 < size && nums[r+1] == target)
                r++;
            else
                break;
        }
        std::vector<int> v;
        if(l > r || nums[l] != target) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        v.push_back(l);
        v.push_back(r);
        return v;
    }
};
int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(7);
    v.push_back(8);
    v.push_back(8);
    v.push_back(10);
	Solution a;
	vector<int> ans;
    ans = a.searchRange(v, 7);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
    cout << endl;
}