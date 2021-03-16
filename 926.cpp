class Solution {
public:
    int minFlipsMonoIncr(string S) {
    	// < firstOnePos is zero, >= first is zero s[firstOnePos] = '1'
        int firstOnePos = 0;
        int afterZeroCount = 0, beforeOneCount = 0;
        for (int i = 0; i < S.length(); i++) {
        	if (S[i] == '0')
        		afterZeroCount++;
        }
        int min = afterZeroCount + beforeOneCount;
        for (;firstOnePos <= S.length();) {
        	if (S[firstOnePos++] == '1') {
        		beforeOneCount++;
        	} else {
        		afterZeroCount--;
        	}
            if (afterZeroCount + beforeOneCount < min)
        		min = afterZeroCount + beforeOneCount;
        }
        return min;
    }
    // 00011000 2
    // 6 0
    // 5 0 1
    // 4 0 2
    // 3 0 3
    // 000 - 3 0
    // 3 0 0
    // 2 0 1
    // 1 0 2
    // 0 0 3
};