class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string map[26];
        int j = 0;
        for(int i=0;i<pattern.size();++i)
        {
            if(j>=s.size()) return false;
            int k = j;
            for(;k<s.size();++k)
            {
                if(s[k]==' ') break;
            }
            string sub = s.substr(j,k-j);
            if(!map[pattern[i]-'a'].empty())
            {
                if(map[pattern[i]-'a']!=sub) return false;
            }
            else
            {
                for(int l=0;l<26;++l)
                {
                    if(map[l]==sub) return false;
                }
                map[pattern[i]-'a'] = sub;
            }
            j = k+1;
        }
        return j==(s.size()+1);
    }
};
