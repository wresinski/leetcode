class Solution {
public:
    int balancedStringSplit(string s) {
        int Rcount = 0,Lcount = 0,count = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='R') Rcount++;
            if(s[i]=='L') Lcount++;
            if(Rcount==Lcount)
            {
                count++;
                Rcount = 0;
                Lcount = 0;
            }
        }
        return count;
    }
};
