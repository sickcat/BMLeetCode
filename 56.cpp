class Solution {
public:
	static bool myCmp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end(), myCmp);
    	vector<vector<int>> ans;
    	if(intervals.size() <= 1)
    		return intervals;
    	ans.push_back(intervals[0]);
    	for(int i = 1; i < intervals.size(); i++) {
    		if(intervals[i][0] <= ans.back()[1])
    			ans.back()[1] = intervals[i][1] > ans.back()[1] ? intervals[i][1] : ans.back()[1];
    		else
    			ans.push_back(intervals[i]);
 	   	}
 	   	return ans;
    }
};