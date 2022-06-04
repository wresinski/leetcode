class Solution {
public:
    vector<int> diStringMatch(string S) {
	int min = 0;
	int max = S.size();
	vector<int> res;
	for(int i=0;i<S.size();++i) {
	    if(S[i]=='I') {
		res.push_back(min++);
	    }
	    else {
		res.push_back(max--);
	    }
	}
	res.push_back(min);
	return res;
    }
    /*
    vector<int> diStringMatch(string S) {
        vector<int> res;
        recursion(0,S.size(),0,S,res);
        return res;
    }
    void recursion(int min,int max,int n,string &S,vector<int> &res)
    {
        if(n==S.size())
        {
            res.push_back(max);
            return;
        }
        if(S[n]=='I') res.push_back(min++);
        else res.push_back(max--);
        recursion(min,max,++n,S,res);
    }
    */
};
