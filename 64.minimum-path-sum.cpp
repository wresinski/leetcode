class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<int> path(m);
	path[0] = grid[0][0];
	for (int i=0; i<n; ++i) {
	    for (int j=0; j<m; ++j) {
		if(i==0&&j==0) continue;
		int up = i>0?path[j]:INT_MAX;
		int left = j>0?path[j-1]:INT_MAX;
		path[j] = grid[i][j] + min(up,left);
	    }
	}
	return path[m-1];
    }
};
