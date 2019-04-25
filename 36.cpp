class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for(int i = 0; i < 9; i++) {
	        vector<bool> nums(9, 1);
	        for(int j = 0; j < 9; j++) {
	        	if(board[i][j] == '.')
	        		continue;
	        	int tmp = board[i][j] - '1';
	        	if(nums[tmp])
	        		nums[tmp] = 0;
	        	else
	        		return false;
	        }
        }
        //check column
        for(int i = 0; i < 9; i++) {
	        vector<bool> nums(9, 1);
	        for(int j = 0; j < 9; j++) {
	        	if(board[j][i] == '.')
	        		continue;
	        	int tmp = board[j][i] - '1';
	        	if(nums[tmp])
	        		nums[tmp] = 0;
	        	else
	        		return false;
	        }
        }
        // check sub-boxes
        for(int i = 0; i < 9; i++) {
        	vector<bool> nums(9, 1);
        	int x = (i/3)*3;
        	int y = (i%3)*3;
	        for(int k = 0; k < 3; k++)
	        	for(int j = 0; j < 3; j++) {
	        		if(board[x+k][y+j] == '.')
	        			continue;
	        		int tmp = board[x+k][y+j];
	        		if(nums[tmp])
	        			nums[tmp] = 0;
	        		else
	        			return false;
	        	}
        }
        return true;
    }
};