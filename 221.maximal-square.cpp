class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
	int x = matrix.size();
	int y = matrix[0].size();
	int res = 0;
	vector<vector<int>> dp(x, vector<int>(y));
	for (int i=0; i<x; ++i) {
	    dp[i][0] = matrix[i][0]-'0';
		res = max(res, dp[i][0]);
	}
	for (int i=0; i<y; ++i) {
	    dp[0][i] = matrix[0][i]-'0';
		res = max(res, dp[0][i]);
	}
	for (int i=1; i<x; ++i) {
	    for (int j=1; j<y; ++j) {
		dp[i][j] = matrix[i][j]=='1'?min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1:0;
		res = max(res, dp[i][j]);
	    }
	}
	return res*res;
    }
};
