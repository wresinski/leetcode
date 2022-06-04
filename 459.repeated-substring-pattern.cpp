class Solution {
public:
    bool repeatedSubstringPattern(string s) {
	int n = s.size();
	int *next = (int*)malloc(sizeof(int)*(n+1));
	getNext(s.c_str(), n+1, next);
	for(int i=1;i<n+1;++i) next[i-1] = next[i] - 1;
	bool ret = next[n - 1] != -1 && n % (n - next[n - 1] - 1) == 0;
	free(next);
	return ret;
    }

    void getNext(const char *t, int tLength, int *next) {
	next[0] = -1;
	next[1] = 0;
	int i = 1;
	int j = next[i];
	i++;
	while (i < tLength) {
	    if (t[i - 1] == t[j]) {
		next[i] = j + 1;
		j++;
		i++;
	    } else if (j == 0) {
		next[i] = j;
		i++;
            } else
                j = next[j];
        }
    }
    /*
    bool repeatedSubstringPattern(string s) {
        for(int i=1;i<=s.size()/2;++i)
        {
            if(s.size()%i!=0) continue;
            bool isMatch = true;
            for(int j=i;j<s.size();++j)
            {
                if(s[j-i]!=s[j]) isMatch = false;
            }
            if(isMatch) return true;
        }
        return false;
    }
    */
};
