class Solution {
public:
    int maxPower(string s) {
        int iMax = s.size()>0;
        int iTemp = 1;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]==s[i-1]) iTemp++;
            else iTemp = 1;
            iMax = max(iMax,iTemp);
        }
        return iMax;
    }
};
