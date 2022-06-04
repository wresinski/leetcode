class Solution {
public:
    int uniquePaths(int m, int n) {
	vector<int> path(n);
	path[0] = 1;
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
	        if(i==0&&j==0) continue;
		int up = i>0?path[j]:0;
		int left = j>0?path[j-1]:0;
		path[j] = up + left;
	    }
	}
	return path[n-1];
    }
};
