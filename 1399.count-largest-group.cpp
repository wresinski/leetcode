class Solution {
public:
    int countLargestGroup(int n) {
        return min(n%10+1,10-n/10%10);
    }
    int getSum(int n)
    {
        int res = 0;
        while(n>0)
        {
            res += n%10;
            n /= 10;
        }
        return res;
    }
};
