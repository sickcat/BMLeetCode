class Solution {
public:
    int n;
	struct Point
	{
		int x;
		int y;
		Point(int i, int j) {
			x = i;
			y = j;
		}
	};
    int largestIsland(vector<vector<int>>& grid) {
        // [1140
        //  1194
        //  5811
        //  1511] 9(更改一个0到1，多搜索n步的问题，标记的问题（回退搜索，回退n步的搜索，标记清空，得到一个矩阵)
    	// 从0开始，假设这个0是1，开始，标记只用一次
    	// 对每一个0，加上旁边的1连通图数量
    	// 找1联通图
    	// 可以使用并查集优化，这个效率太低了
    	n = grid.size();
    	int max = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			vector<Point> surround;
    			int size = bfsGetSize(grid, i, j, surround);
    			if (size > max) {
    				max = size;
    			}
    			for (Point p : surround) {
    				grid[p.x][p.y] += size;
    				if (grid[p.x][p.y]+2 > max) {
    					max = grid[p.x][p.y]+2;
    				}
    			}
    		}
    	}
    	return max/2;
    }

    int bfsGetSize(vector<vector<int>>& grid, int i, int j, vector<Point>& surround) {
    	if (i < 0 || i >= n || j < 0 || j >= n) {
    		return 0;
    	}
    	if (grid[i][j] == -1) {
    		return 0;
    	} else if (grid[i][j] != 1) {
    		// 这里需要去重
    		for (Point p : surround) {
    			if (p.x = i && p.y = j) {
    				return 0;
    			}
    		}
    		surround.push_back(Point(i, j));
    		return 0;
    	} else {
    		grid[i][j] = -1;
    		// use 2 to avoid 1
    		return 2 + bfsGetSize(grid, i-1, j, surround) + bfsGetSize(grid, i+1, j, surround)
    			+ bfsGetSize(grid, i, j-1, surround) + bfsGetSize(grid, i, j+1, surround);
    	}
    }
};