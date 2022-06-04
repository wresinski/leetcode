class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string sub = str1.substr(0,gcd(str1.size(),str2.size()));
        int m = str1.size()/sub.size(),n = str2.size()/sub.size();
        string s1,s2;
        for(int i=0;i<m;++i)
        {
            s1 += sub;
        }
        for(int i=0;i<n;++i)
        {
            s2 += sub;
        }
        return (s1==str1&&s2==str2)?sub:"";
    }
    
    int gcd(int x, int y){
        int temp;
        if(x<y){
            temp = x;
            x = y;
            y = temp;
        }
        while(x%y!=0){
            temp = x%y;
            x = y;
            y = temp;
        }
        return y;
    }
};
