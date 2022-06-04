class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j = s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};