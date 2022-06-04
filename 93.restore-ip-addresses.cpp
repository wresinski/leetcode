class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	backtrack(s, 0, ans);
	return res;
    }
    void backtrack(string& s, int i, vector<string>& ans) {
	if (i==s.size()&&ans.size()==4) {
	    res.emplace_back(ans[0]+'.'+ans[1]+'.'+ans[2]+'.'+ans[3]);
	    return;
	}
	if (s[i]=='0') {
	    ans.emplace_back("0");
	    backtrack(s, i+1, ans);
	    ans.pop_back();
	}
	else {
	    for (int j=i; j<s.size()&&j<i+3; ++j) {
		string temp = s.substr(i,j-i+1);
		if (atoi(temp.c_str())<=255) {
		    ans.emplace_back(temp);
		    backtrack(s, j+1, ans);
		    ans.pop_back();
		}
		else {
		    break;
		}
	    }
	}
    }
};
