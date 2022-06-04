class Solution {
public:
    // 按括号长度递归
    vector<vector<string>> map;
    vector<string> generateParenthesis(int n) {
	map.resize(n+1);
	generate(n);
	return map[n];
    }
    void generate(int n) {
    	if (map[n].size()!=0) return;
	if (n==0) map[n].emplace_back("");
    	for (int i=1; i<2*n; i=i+2) {
    	    generate((i-1)/2);
    	    generate(n-(i+1)/2);
    	    for (string &a : map[(i-1)/2]) {
    		for (string &b : map[n-(i+1)/2]) {
    		    map[n].emplace_back('('+a+')'+b);
    		}
    	    }
    	}
    }
    /*
    // 回溯
    vector<string> res;
    vector<string> generateParenthesis(int n) {
	string s;
	backtrace(n, n, s);
	return res;
    }
    void backtrace(int m, int n, string& s) {
	if(m==0&&n==0) {
	    res.emplace_back(s);
	    return;
	}

	if (m>0) {
	    s += '(';
	    backtrace(m-1, n, s);
	    s = s.substr(0, s.size()-1);
	}
	if (n>0&&n>m) {
	    s += ')';
	    backtrace(m, n-1, s);
	    s = s.substr(0, s.size()-1);
	}
    }
    */
};
