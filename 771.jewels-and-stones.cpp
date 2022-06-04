class Solution {
public:
    int numJewelsInStones(string J, string S) {
	char list[256] = {0};
	int res = 0;
	for(int i=0;i<J.size();++i) {
	    list[J[i]] = 1;
	}
	for(int i=0;i<S.size();++i) {
	    if(list[S[i]])
		++res;
	}
	return res;
	/*
        bool list[52] = {false};
        int res = 0;
        for(int i=0;i<J.size();++i)
        {
            int n = (J[i]-'a'>=0)?(J[i]-'a'):(J[i]-'A'+26);
            list[n] = true;
        }
        for(int i=0;i<S.size();++i)
        {
            int n = (S[i]-'a'>=0)?(S[i]-'a'):(S[i]-'A'+26);
            if(list[n]) res++;
        }
        return res;
	*/
    }
};
