class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(m, 0);
        ans[0] = grid[0][0];
        for(int i = 1; i < m; i++)
            ans[i] = ans[i-1] + grid[i][0];
        for(int i = 1; i < n; i++) {            
            ans[0] = ans[0] + grid[0][i];
            for(int j = 1; j < m; j++)
                ans[j] = min(ans[j-1], ans[j]) + grid[j][i];
        }
        return ans[m-1];
    }
};