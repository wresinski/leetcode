class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result;
        for(int i=0;i<code.size();++i)
        {
            int temp = 0;
            if(k>0)
            {
                for(int j=i+1;j<=i+k;++j)
                {
                    temp += code[GetNo(code.size(),j)];
                }
            }
            else if(k<0)
            {
                for(int j=i-1;j>=i+k;--j)
                {
                    temp += code[GetNo(code.size(),j)];
                }
            }
            
            result.push_back(temp);
        }
        return result;
    }

    int GetNo(int n, int i)
    {
        return (i>=0)?i%n:(n+i%n);
    }
};
