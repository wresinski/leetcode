class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	int n = s.size();
	int map[128];
	for (int i=0;i<128;++i) map[i] = -1;
	int max_length = 0;
	int i=0;
	int j=0;
	while (i<n) {
	    if (j<=map[s[i]]) { // 注意收缩的判断条件
		max_length = max(max_length,i-j);
		j = map[s[i]]+1;
	    }
	    map[s[i]] = i;
	    i++;
	}
	max_length = max(max_length,i-j);
	return max_length;
    }
};
