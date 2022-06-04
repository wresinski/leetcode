class Solution {
public:
    vector<vector<string>> partition(string s) {
	int n = s.size();
	vector<vector<int>> f(n, vector<int>(n, -1));
	/*
	for (int i=n-1; i>=0; --i) {
	    for (int j=i+1; j<n; ++j) {
	        f[i][j] = f[i+1][j-1]&&(s[i]==s[j]);
	    }
	}
	*/

	vector<string> ans;
	vector<vector<string>> res;
	backtrack(s, 0, f, ans, res);
	return res;
    }

    void backtrack(string &s, int i, vector<vector<int>> &f, vector<string> &ans, vector<vector<string>> &res) {
	if(i==s.size()) {
	    res.push_back(ans);
	    return;
	}
	for (int j=i; j<s.size(); ++j) {
	    if (isPalindrome(s, i, j, f)) {
	        ans.push_back(s.substr(i,j-i+1));
		backtrack(s, j+1, f, ans, res);
		ans.pop_back();
	    }
	}
    }

    // 记忆化搜索
    int isPalindrome(string &s, int i, int j, vector<vector<int>> &f) {
	if (f[i][j]!=-1) {
	    return f[i][j];
	}

	if (i>=j) {
	    return f[i][j]=1;
	}

	return f[i][j]=(isPalindrome(s, i+1, j-1, f)&&(s[i]==s[j]));
    }
};
