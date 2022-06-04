class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
	vector<int> res;
	int n1 = p.size();
	int n2 = s.size();
	vector<int> map(26);
	for (int i=0; i<n1; ++i) {
	    map[p[i]-'a']--;
	}

	int i = 0, j = 0;
	while (i<n2) {
	    map[s[i]-'a']++;
	    while (map[s[i]-'a']>0) {
		map[s[j++]-'a']--;
	    }
	    if (i-j+1==n1) res.emplace_back(j);
	    i++;
	}
	return res;
    }
};
