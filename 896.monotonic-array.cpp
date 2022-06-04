class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increase = true;
        bool decrease = true;
        for(int i=1;i<A.size();++i)
        {
            if(A[i]<A[i-1]) increase = false;
            else if(A[i]>A[i-1]) decrease = false;
        }
        return increase||decrease;
    }
};
