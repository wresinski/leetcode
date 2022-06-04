class Solution {
public:
    // Manacher算法
    string longestPalindrome(string s) {
	string t = "#";
	for (char& c : s) {
	    t += c;
	    t += '#';
	}
	s = t+'#';

	int res = 1;
	int x = 0, y = 0;
	int center = -1, right = -1;
	vector<int> len(s.size());
	for (int i=0; i<s.size(); ++i) {
	    if (i<=right) {
	        int left = center*2-right;
		int len_min = min(len[left], right-i);
		len[i] = helper(s, i-len_min, i+len_min);
	    }
	    else {
		len[i] = helper(s, i, i);
	    }
	    
	    if (i+len[i]>right) {
		right = i+len[i];
		center = i;
	    }

	    if (len[i]*2+1>res) {
		res = len[i]*2+1;
		x = i-len[i];
		y = i+len[i];
	    }
	}

	string string_res;
	for (int i=x; i<=y; ++i) {
	    if (s[i]!='#') {
	        string_res += s[i];
	    }
	}

	return string_res;
    }
    int helper(string& s, int i, int j) {
	int res = 1;
	while (i>0&&j<s.size()-1&&s[--i]==s[++j]) {
	    if (res<j-i+1) {
		res = j-i+1;
	    }
	}
	return (res-1)/2;
    }
    /*
    // 中心扩展算法
    string longestPalindrome(string s) {
	int n = s.size();
	int res = 1;
	int x = 0, y = 0;
	for (int k=0; k<n; ++k) {
	    int i = k;
	    int j = k;
	    while (i>0&&j<n-1&&s[--i]==s[++j]) {
		if (res<j-i+1) {
		    res = j-i+1;
		    x = i;
		    y = j;
		}
	    }
	}
	for (int k=0; k<n-1; ++k) {
	    int i = k;
	    int j = k+1;
	    if (s[i]!=s[j]) continue;
	    if (res<j-i+1) {
		res = j-i+1;
		x = i;
		y = j;
	    }
	    while (i>0&&j<n-1&&s[--i]==s[++j]) {
		if (res<j-i+1) {
		    res = j-i+1;
		    x = i;
		    y = j;
		}
	    }
	}
	return s.substr(x, res);
    }
    */
    /*
    string longestPalindrome(string s) {
	int n = s.size();
	vector<vector<int>> map(n, vector<int>(n, 1));
	int res = 1;
	int x = 0, y = 0;
	for (int k=1; k<n; ++k) {
	    for (int i=0,j=k; i<n&&j<n; ++i,++j) {
		map[i][j] = map[i+1][j-1]&&s[i]==s[j];
		if (map[i][j]&&j-i+1>res) {
		    res = j-i+1;
		    x = i;
		    y = j;
		}
	    }
	}
	return s.substr(x, res);
    }
    */
};
