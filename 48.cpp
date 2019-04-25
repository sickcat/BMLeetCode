class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int k = matrix.size()/2;
        for(int i = 0; i < k; i++)
	        in_rotate(matrix, i, matrix.size() - 2*i);
    }
    inline void in_rotate(vector<vector<int>>& matrix, int start, int count) {
    	int tmp;
    	for(int i = 0; i < count-1; i++) {
    		int x = start, y = start + i;
    		int tox = start + i, toy = start + count - 1;
    		int tox2 = start + count - 1, toy2 = start + count - 1 - i;
    		int tox3 = start + count - 1 - i, toy3 = start;
    		tmp = matrix[tox][toy];
    		matrix[tox][toy] = matrix[x][y];
    		matrix[x][y] = matrix[tox3][toy3];
    		matrix[tox3][toy3] = matrix[tox2][toy2];
    		matrix[tox2][toy2] = tmp;
    	}
    }
};