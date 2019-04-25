class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, max = 0;
        int size = s.length();
        for(int i = 0; i < size; i++) {
        	if(s[i] == '(')
        		left++;
        	else
        		right++;
        	if(left == right)
        		max = right*2 > max ? right*2 : max;
        	else if(right > left) {
        		left = 0;
        		right = 0;
        	}
        }
        left = 0;
        right = 0;
        for(int i = size - 1; i >= 0; i--) {
        	if(s[i] == '(')
        		left++;
        	else
        		right++;
        	if(left == right)
        		max = right*2 > max ? right*2 : max;
        	else if(left > right) {
        		left = 0;
        		right = 0;
        	}

        }
        return max;
    }
};