class Solution {
public:
    int uniquePaths(int m, int n) {
        int max = m+n-2;
        if(max <= 0)
        	return 1;
        int min = m < n ? m-1 : n-1;
        long ans = 1;
        for(int i = max; i > max - min; i--)
        	ans *= i;
        for(int i = min; i > 1; i--)
        	ans /= i;
        return (int)ans;
    }
};