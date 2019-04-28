class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, -1));
        int count = 1;
        int j;
        for(int i = 0; i < (n+1)/2; i++) {
        	for(j = i; j < n-i; j++)
        		ans[i][j] = count++;
        	for(j = i + 1; j < n - i; j++)
        		ans[j][n-i-1] = count++;
        	for(j = n-i-2; j >= i; j--)
        		ans[n-i-1][j] = count++;
        	for(j = n - i - 2; j > i; j--)
        		ans[j][i] = count++;
        }
        return ans;
    }
};