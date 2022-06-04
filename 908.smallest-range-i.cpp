class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = INT_MAX,max = INT_MIN;
        for(int i=0;i<A.size();++i)
        {
            if(min>A[i]) min = A[i];
            if(max<A[i]) max = A[i];
        }
        int res = max-min-K*2;
        return res>0?res:0;
    }
};
