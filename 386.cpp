class Solution {
private:
	int globalN;
public:
    vector<int> lexicalOrder(int n) {
        // 1到n字典序列 13
        // 1 10 100 1000 1001 1002 1003 ...  101 1010
        // 肯定是12345678这么补充的，末尾的时候这么上，小于n的时候都能这么上
        // 得到位数，n位
        // 1 到 n 位 第n位开始补
        // 1 到 n，利用函数确定每位的位置，这个函数和n有关的，感觉会很难
        // 位置的1到n，每一个位置放什么
        // 补充什么，然后递归下去，最大递归深度就和位数有关了 358
        // 299 300 小于n的，但是需要从300开始了，3
        // 199
        vector<int> ans(n, 0);
        int pos = 0, add = 1;
        while (pos < n) {
        	ans[pos] = add;
        	if (add * 10 <= n) {
        		add *= 10;
        	} else {
        		if (add + 1 <= n) {
        			add++;
        			while (add % 10 == 0) {
        				add = add/10;
        			}
        		} else {
        			// special
        			add = (add/10+1);
        			while (add % 10 == 0) {
        				add = add/10;
        			}
        		}
        	}
        	pos++;
        }
        return ans;
    }

};