class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<int> prime = {2,3,5,7,11,13,17,19};
        int res = 0;
        for(int i=L;i<=R;++i)
        {
            int count1 = 0;
            int n = i;
            while(n>0)
            {
                count1 += n%2;
                n /= 2;
            }
            if(find(prime.begin(),prime.end(),count1)!=prime.end()) res++;
        }
        return res;
    } 
};
