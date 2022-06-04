class Solution {
public:
    int minCut(string s) {
	int n = s.size();
	vector<vector<int>> f(n, vector<int>(n, 1));
	for (int i=n-1; i>=0; --i) {
	    for (int j=i+1; j<n; ++j) {
	        f[i][j] = f[i+1][j-1]&&(s[i]==s[j]);
	    }
	}

	vector<int> res(n, INT_MAX);
	for (int i=0; i<n; ++i) {
	    if (f[0][i]) {
	        res[i] = 0;
		continue;
	    }
	    int j = i-1;
	    while (j>=0) {
		if (f[j+1][i]) {
		    res[i] = min(res[i], res[j]+1);
		    if (res[j]==0) break; // 后面不可能更小了，提前结束
		}
		j--;
	    }
	}
	return res[n-1];
    }
};
