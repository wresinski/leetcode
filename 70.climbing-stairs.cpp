class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int* chart = new int[n];
        chart[0] = 1;
        chart[1] = 2;
        for(int i=2;i<n;++i)
        {
            chart[i] = chart[i-1]+chart[i-2];
        }
        int res = chart[n-1];
        delete[] chart;
        return res;
       // if(n==2) return 2;
       // else if(n==1) return 1;
       // return climbStairs(n-1)+climbStairs(n-2);
    }
};
