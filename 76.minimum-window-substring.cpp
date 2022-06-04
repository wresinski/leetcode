class Solution {
public:
    string minWindow(string s, string t) {
	int ns = s.size();
	int nt = t.size();
	int map[128] = {0};
	for (int i=0; i<nt; ++i) {
	    map[t[i]]++;
	}

	int i = -1,j = 0;
	int min_len = INT_MAX,min_i = -1,min_j = -1;
	while (i<ns-1) {
	    if (map[s[++i]]>0) {
		nt--;
	    }
	    map[s[i]]--;
	    if (nt==0) {
	        while (map[s[j]]<0) {
		    map[s[j++]]++;
		}
		if (i-j+1<min_len) {
		    min_len = i-j+1;
		    min_i = i;
		    min_j = j;
		}
		map[s[j++]]++;
		nt++;
	    }
	}
	return min_i>=0?s.substr(min_j,min_i-min_j+1):"";
    }
    /*
    int maps[128] = {0};
    int mapt[128] = {0};
    string minWindow(string s, string t) {
	for (int i=0; i<t.size(); ++i) {
	    mapt[t[i]]++;
	}
	int i = -1,j = 0;
	int min_len = INT_MAX,min_i = -1,min_j = -1;
	while (i<(int)(s.size()-1)) {
	    maps[s[++i]]++;
	    while (check()) {
		if (i-j+1<min_len) {
		    min_len = i-j+1;
		    min_i = i;
		    min_j = j;
		}
	        maps[s[j++]]--;
	    }
	}
	return min_i>=0?s.substr(min_j,min_i-min_j+1):"";
    }

    bool check() {
	for (int i=0;i<256;++i) {
	    if (mapt[i]>0&&maps[i]<mapt[i]) return false; 
	}
	return true;
    }
    */
};
