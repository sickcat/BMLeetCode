#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
    	int i = s.length() - 1;
    	for(; i >= 0; i--)
    		if(s[i] != ' ')
    			break;
    	int tmp = i;
        for(; i >= 0; i--)
        	if(s[i] == ' ')
        		return tmp - i;
        return i == -1 ? tmp+1 : 0;
    }
};
int main() {
	Solution a;
	cout << a.lengthOfLastWord("   ") << endl;
}