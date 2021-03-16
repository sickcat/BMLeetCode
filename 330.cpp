// 关键，设置miss为当前不能构建的最小值，当miss>=n的时候算法结束
// 一个数组可以组成的怎么处理，进入和不进入，两种
// miss += miss 怎么解释 以及 nums[i] <= miss, 仅遍历一遍的怎么解释
// 更进一步解释: [3,5] - 3,5,8 [1,3,5] - 1,3,4,5,6,8,9
// 输入有序
// [1,n]最终数组里面肯定有1，2，这些，所以可以这么干
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int miss = 1, add = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                // 把miss补充进数组了
                miss = miss + miss;
                add++;
            }
        }
        return add;
    }
};