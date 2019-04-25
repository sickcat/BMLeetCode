#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isMatch(string s, string p) {
	int m = s.length(), n = p.length();
	vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
	dp[0][0] = 1;
	for(int j = 2; j <= n; j += 2)
		if(p[j-1] == '*')
			dp[0][j] = dp[0][j-2];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(s[i] == p[j] || p[j] == '.') {
				dp[i+1][j+1] = dp[i][j];
			} else if(p[j] == '*') {
				if(s[i] != p[j-1] && p[j-1] != '.')
					dp[i+1][j+1] = dp[i+1][j-1];
				else {
					dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
				}
			}
		}
	}
	// for(int i = 0; i <= m; i++) {
	// 	for(int j = 0; j <= n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	return dp[m][n];
}
int main() {
	string s;
	string p;
	cin >> s;
	cin >> p;
	cout << isMatch(s, p) << endl;
}