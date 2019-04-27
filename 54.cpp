#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	// 1 2 3 4
    	// 5 6 7 8
    	// 9 10 11 12
        vector<int> ans;
        int m = matrix.size();
        if(m == 0)
        	return ans;
        int n = matrix[0].size();
        int min = m < n ? m : n;
        int size = (min%2 == 0) ? min/2 : min/2+1;
        for(int i = 0; i < size; i++) {
        	//cout << "???" << i << endl;
        	// 1 2 3 4
        	for(int j = i; j < n-i; j++)
        		ans.push_back(matrix[i][j]);
        	// 8 12
        	for(int j = i + 1; j < m-i; j++)
        		ans.push_back(matrix[j][n-i-1]);
        	// 11 10 9
        	if(m-i-1 != i) {
	        	for(int j = n-i-2; j >= i; j--)
    	    		ans.push_back(matrix[m-i-1][j]);
	        	// 5
        	}
        	if(i != n - i - 1)
	        	for(int j = m - i - 2; j >= i + 1; j--)
    	    		ans.push_back(matrix[j][i]);
        	//cout << ans[ans.size() - 1] << endl;
        }
        return ans;
    }
};
int main() {
	vector<vector<int> > t;
	int count = 1;
	for(int i = 0; i < 4; i++) {
		vector<int> tmp;
		for(int j = 0; j < 1; j++) {
			tmp.push_back(count);
			count++;
		}
		t.push_back(tmp);
	}
	Solution a;
	vector<int> ans = a.spiralOrder(t);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}