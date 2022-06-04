class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
	int temp1 = 0;
	int temp2 = 1;
        for(int i=2;i<=n;++i)
        {
            int temp3 = temp1+temp2;
	    temp1 = temp2;
	    temp2 = temp3;
        }
        return temp2;
    }
};
