class Solution {
public:
    bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();

	auto match = [&](int i, int j) {
	    if (i<0||j<0) return 0;
	    if (p[j]=='.') {
		return 1;
	    }
	    else if (s[i]==p[j]) {
	        return 1;
	    }
	    else return 0;
	};
	    
	vector<vector<int>> dp(m+1, vector<int>(n+1));
	dp[0][0] = 1;
	for (int i=0; i<=m; ++i) {
	    for (int j=1; j<=n; ++j) {
		if (p[j-1]=='*') {
		    if (match(i-1, j-2)) {
			dp[i][j] = dp[i-1][j]||dp[i][j-2];
		    }
		    else {
			dp[i][j] = dp[i][j-2];
		    }
		}
		else {
		    if (match(i-1, j-1)) {
			dp[i][j] = dp[i-1][j-1];
		    }
		} 
	    }
	}
	return dp[m][n];
    }
};
