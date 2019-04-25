class Solution {
private:
	struct item{
		int count;
		bitset<9> positive("111111111");
		char val;
		item() count(0), val(0) {};
	};
	void update(array<array<item, 9>, 9> &norm, int i, int j, char val) {
		int row = (i/3)*3, column = (i%3)*3;
		int t = val - '1';
		for(int k = 0; k < 9; k++) {
			if(norm[(i+k)%9][j].count != '-1')
				norm[(i+k)%9][j].positive[t] = 0;
			if(norm[i][(j+k)%9].count != '-1')
				norm[i][(j+k)%9].positive[t] = 0;
			if(norm[row + k/3][column + k%3].count != '-1')
				norm[row + k/3][column + k%3].positive[t] = 0;
		}
	}
	void getCount() {

	}
	array<array<item, 9>, 9> norm;
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
        	for(int j = 0; j < 9; j++) {
        		if(board[i][j] != '.') {
        			norm[i][j].val = board[i][j];
        			norm[i][j].count = -1;
        			update(i, j, board[i][j]);
        		}
        	}
        }
        getCount();
    }
};