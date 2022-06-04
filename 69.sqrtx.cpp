class Solution {
public:
    int mySqrt(int x) {
        double x1 = x;
        while(x1*x1-x>10e-6)
        {
            x1 = (x1*x1+x)/x1/2;
        }
        return (int)x1;
    }
};
