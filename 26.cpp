#include<iostream>
#include<vector>
using namespace std;
// int removeDuplicates(vector<int>& nums) {
//     if(nums.size() == 0)
//     	return 0;
//     int pre = nums[0], count = 1;
//     int size = nums.size();
//     for(int i = 0; i < size; i++)
//     	if(nums[i] == pre)
//     		continue;
//     	else {
//     		nums[count] = nums[i];
//     		count++;
//     		pre = nums[i];
//     	}
//     return count;
// }
int removeDuplicates(vector<int>& nums) {
    int count = 0;
    int size = nums.size();
    for(int i = 1; i < size; i++)
    	if(nums[i] == nums[i-1])
    		count++;
    	else
    		nums[i - count] = nums[i];
    return size - count;
}
int main() {
	std::vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	int k = removeDuplicates(v);
	for(int i = 0; i < k; i++)
		cout << v[i] << endl;
}