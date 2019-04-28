class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int mintmp = -1;
        for(int i = 0; i < intervals.size(); i++) {
        	if(intervals[i][1] < newInterval[0]) {
        		ans.push_back(intervals[i]);
        		continue;
        	}
        	if(intervals[i][0] > newInterval[1]) {
        		ans.push_back(intervals[i]);
        		continue;
        	}
        	if(mintmp == -1)
        		mintmp = intervals[i][0] < newInterval[0] ? intervals[i][0] : newInterval[0];
        	while(i < intervals.size()) {
        		if(intervals[i] < )
        			
        		i++;
        	}
        }
    }
};