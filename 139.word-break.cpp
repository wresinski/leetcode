class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
	int maxl = 0;
	unordered_set<string> set;
	for (auto iter = wordDict.begin(); iter!=wordDict.end(); ++iter) {
	    set.insert(*iter);
	    maxl = max(maxl,(int)(*iter).size());
	}
	int n = s.size();
	vector<int> b(n);
	for (int i=0; i<n; ++i) {
	    for (int j=i; j>i-maxl&&j>=0; --j) {
	        if ((j==0||b[j-1])&&set.count(s.substr(j,i-j+1))) { // 当j==0当s1为空串，只判断s2是否在set中
		    b[i] = 1;
		    break;
		}
	    }
	}
	return b[n-1];
    }
};
