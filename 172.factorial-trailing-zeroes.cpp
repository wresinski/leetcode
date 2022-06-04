class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int i = 5;
        while(n>=i)
        {
            res += n/i;
            i *= 5;
        }
        return res;
    }
};
