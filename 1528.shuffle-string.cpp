class Solution {
public:
/* 
    //开辟数组
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(),0);
        for(int i=0;i<s.size();++i)
        {
            res[indices[i]] = s[i];
        }
        return res;
    }
*/
    //原地置换
    string restoreString(string s, vector<int>& indices) {
        for(int i=0;i<s.size();++i){
            char c = s[i];
            int d = indices[i];
            while(d!=indices[d]){
                char tempc = s[d];
                s[d] = c;
                c = tempc;
                int tempd = indices[d];
                indices[d] = d;
                d = tempd;
            }
        }
        return s;
    }
};
