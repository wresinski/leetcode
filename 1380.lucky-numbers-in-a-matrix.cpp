class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int* col = new int[matrix[0].size()];
        int* row = new int[matrix.size()];
        for(int i=0;i<matrix[0].size();++i) col[i] = -1;
        for(int i=0;i<matrix.size();++i) row[i] = -1;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                if(col[j]==-1)
                {   
                    int max = INT_MIN;
                    for(int k=0;k<matrix.size();++k)
                    {
                        if(max<matrix[k][j]) max = matrix[k][j];
                    }
                    col[j] = max;
                }
                if(row[i]==-1)
                {   
                    int min = INT_MAX;
                    for(int k=0;k<matrix[0].size();++k)
                    {
                        if(min>matrix[i][k]) min = matrix[i][k];
                    }
                    row[i] = min;
                }
                if(matrix[i][j]==col[j]&&matrix[i][j]==row[i]) res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
