class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<int> path(n);
	path[0] = obstacleGrid[0][0]==0?1:0;
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
	        if(i==0&&j==0) continue;
		int up = i>0?path[j]:0;
		int left = j>0?path[j-1]:0;
		path[j] = obstacleGrid[i][j]==0?up+left:0;
	    }
	}
	return path[n-1];
    }
};
