#include<iostream>
#include<string>
#include<vector>
using namespace std;
string minWindow(string s, string t) {
    vector<int> map(128,0);
    for(auto c: t) map[c]++;
    int counter=t.size(), begin=0, end=0, d=s.length() + 10, head=0;
    while(end<s.size()) {
        if(map[s[end++]]-->0) counter--; //in t
    	cout << end << " " << head << " " << map['A'] << map['B'] << map['C'] << map['N'] << endl;
        while(counter==0) {
            if(end-begin<d)  d=end-(head=begin);
            if(map[s[begin++]]++==0) counter++;
        }
    }
    return d==s.length() + 10? "":s.substr(head, d);
}
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter = t.length();
        int begin = 0, d = s.length() + 1, flag = 1, head = 0;
        for(int i = 0; i < s.length(); i++) {
            if(map[s[i]] <= 0 && flag) {begin = i+1;continue;} //ignore prefix
            if(map[s[i]] > 0) {
                counter--;
            }
            map[s[i]]--;
            flag = 0;
            if(counter == 0) {
                if(d > i-begin + 1) d = i-(head=begin) + 1;
                for(int j = begin; j <= i; j++) {
                    if(map[s[j]]++ >= 0)
                        counter++;
                }
                //cout << counter << endl;
                flag = 1;
            }
        }
        return d == s.length() + 1 ? "" : s.substr(head, d);
    }
};
int main() {
	string s = "BDAB", t = "AB";
	cout << minWindow(s, t) << endl;
	int a = 0, b = 1, c = 4;
    Solution fuck;
    cout << fuck.minWindow(s, t) << endl;
	cout << c-(a=b) << endl;
	cout << a << b << c << endl;;
}