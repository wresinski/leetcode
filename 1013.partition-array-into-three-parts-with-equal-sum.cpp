class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int i=0;i<A.size();++i)
        {
            sum += A[i];
        }
        if(sum%3) return false;
        sum /= 3;
        int temp = 0;
        int i = 0;
        int res = 0;
        while(i<A.size())
        {
            temp += A[i++];
            if(temp==sum)
            {
                res++;
                temp = 0;
                if(res==2) break;
            }
        }
        return res==2&&i<A.size();
    }
};
