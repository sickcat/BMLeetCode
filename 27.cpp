#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	int size = nums.size();
	int count = 0;
	for(int i = 0; i < size;)
		if(nums[i] == val) {
			nums[i] = nums[size - 1];
			nums[size - 1] = val;
			size -= 1;
			count += 1;
		} else
			i++;
	return nums.size() - count;
}
int main() {
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	int k = removeElement(v, 3);
	for(int i = 0; i < k; i++)
		cout << v[i] << endl;
}