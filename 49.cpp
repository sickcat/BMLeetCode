class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string> > ans;
        vector<bitset<26> > hashs;
        vector<array<int, 26> > count;
        
        for(int i = 0; i < strs.size(); i++) {
        	bitset<26> tmp;
        	array<int, 26> count_tmp;
        	count_tmp.fill(0);
        	for(int k = 0; k < strs[i].length(); k++) {
        		tmp[strs[i][k] - 'a'] = 1;
        		count_tmp[strs[i][k] - 'a'] += 1;
        	}
        	int j = 0;
        	while(j < hashs.size()) {
        		if(((hashs[j])&tmp) == hashs[j] && ((hashs[j])&tmp) == tmp) {
        			int flag = 1;
        			for(int k = 0; k < 26; k++)
        				if(count[j][k] != count_tmp[k]) {
        					flag = 0;
        					break;
        				}
        			if(flag == 0) {
        				j++;
        				continue;
        			}
	        		ans[j].push_back(strs[i]);
        			break;
        		}
        		j++;
        	}
        	if(j == hashs.size()) {
        		vector<string> inv;
        		inv.push_back(strs[i]);
        		ans.push_back(inv);
        		hashs.push_back(tmp);
        		count.push_back(count_tmp);
        	}
        }
        return ans;
    }
};