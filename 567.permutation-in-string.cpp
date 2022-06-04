class Solution {
public:
    // 双指针
    bool checkInclusion(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	vector<int> map(26);
	for (int i=0; i<n1; ++i) {
	    map[s1[i]-'a']--;
	}

	int i = 0, j = 0;
	while (i<n2) {
	    map[s2[i]-'a']++;
	    while (map[s2[i]-'a']>0) {
		map[s2[j++]-'a']--;
	    }
	    if (i-j+1==n1) return true;
	    i++;
	}
	return false;
    }
    /*
    // 滑动窗口
    bool checkInclusion(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1>n2) return false;
	vector<int> map(26);
	for (int i=0; i<n1; ++i) {
	    map[s2[i]-'a']++;
	    map[s1[i]-'a']--;
	}
	int diff = 0;
	for (int i=0; i<26; ++i) {
	    if (map[i]!=0) {
		diff++;
	    }
	}
	if(diff==0) return true;

	int j = n1;
	while (j<n2) {
	    if (s2[j]!=s2[j-n1]) {
		if (map[s2[j]-'a']==0) diff++;
		else if(map[s2[j]-'a']==-1) diff--;
		if (map[s2[j-n1]-'a']==0) diff++;
		else if(map[s2[j-n1]-'a']==1) diff--;
		map[s2[j]-'a']++;
		map[s2[j-n1]-'a']--;
	    }
	    if(diff==0) return true;
	    j++;
	}
	return false;
    }
    */
    /*
    // 滑动窗口
    bool checkInclusion(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	vector<int> map1(26),map2(26);
	for (int i=0; i<n1; ++i) {
	    map1[s1[i]-'a']++;
	}

	bool res = false;
	int j = 0;
	while (j<n2) {
	    map2[s2[j]-'a']++;
	    if (j>=n1) {
		map2[s2[j-n1]-'a']--;
	    }
	    if ((j>=n1-1)&&map1==map2) return true;
	    j++;
	}
	return false;
    }
    */
};
