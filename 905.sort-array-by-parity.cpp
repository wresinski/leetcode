class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0,j = A.size()-1;
        while(i<j)
        {
            if(A[i]%2==1&&A[j]%2==0)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            if(A[i]%2==0) i++;
            if(A[j]%2!=0) j--;
        }
        return A;
    }
};
