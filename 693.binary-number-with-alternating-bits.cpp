class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n%2;
        n /= 2;
        while(n>0)
        {
            if(n%2==pre) return false;
            pre = n%2;
            n /= 2;
        }
        return true;
    }
};
