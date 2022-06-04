class Solution {
public:
    // up-to-donw
    int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<int> path(n);
	path[0] = triangle[0][0];
	for (int i=1; i<n; ++i) {
	    path[i] = triangle[i][i] + path[i-1];
	    for (int j=i-1; j>0; --j) {
		path[j] = triangle[i][j] + min(path[j-1],path[j]);
	    }
	    path[0] = triangle[i][0] + path[0];
	}
	int min_value = INT_MAX;
	for (int i=0; i<n; ++i) {
	    if (path[i]<min_value) min_value = path[i];
	}
	return min_value;
    }
    /*
    // down-to-up
    int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<int> path(n);
	for (int i=n-1; i>=0; --i) {
	    for (int j=0; j<=i; ++j) {
	        if (i==n-1) {
		    path[j] = triangle[i][j];
		}
		else {
		    path[j] = triangle[i][j] + min(path[j],path[j+1]);
		}
	    }
	}
	return path[0];
    }
    */
};
