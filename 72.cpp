class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> dp(n+1, 0);
        for(int j = 1; j<= n; j++)
        	dp[j] = j;
        for(int i = 1; i <= m; i++) {
        	for(int j = 1; j <= n; j++)
        		if(word1[i] == word2[j])
        			dp[j] = min(dp[j-1])
        }
        return dp[n];
    }
};