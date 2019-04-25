#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
        	int mid = (l + r)/2;
        	if(nums[mid] > nums[r])
        		l = mid + 1;
        	else
        		r = mid;
        }
        int rot = l;
        l = 0, r = nums.size() - 1;
       	while(l <= r) {
       		int mid = (l + r)/2;
       		int real = (mid + rot) % nums.size();
       		if(nums[real] == target) 
       			return real;
       		if(nums[real] < target)
       			l = mid + 1;
       		else
       			r = mid-1;
       	}
       	return -1;
    }
};
int main() {
	Solution a = Solution();
	std::vector<int> v;
	// for(int i = 4; i <= 8; i++)
	// 	v.push_back(i);
	// for(int i = 0; i <= 2; i++)
	// 	v.push_back(i);
	// for(int i = 0; i < 10; i++)
	// 	cout << a.search(v, i) << endl;
	v.push_back(3);
	v.push_back(1);
	cout << a.search(v, 0) << endl;
}