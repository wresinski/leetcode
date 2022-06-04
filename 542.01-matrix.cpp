class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        queue<pair<int,int>> qu;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    res[i][j] = 0;
                    qu.push(pair<int,int>(i,j));
                }
                else
                {
                    res[i][j] = INT_MAX;
                }
            }
        }
        while(!qu.empty())
        {
            int i = qu.front().first;
            int j = qu.front().second;
            qu.pop();
            if(i-1>=0&&res[i-1][j]>res[i][j]+1) 
            {
                res[i-1][j] = res[i][j]+1;
                qu.push(pair<int,int>(i-1,j));
            }
            if(j-1>=0&&res[i][j-1]>res[i][j]+1) 
            {
                res[i][j-1] = res[i][j]+1;
                qu.push(pair<int,int>(i,j-1));
            }
            if(i+1<m&&res[i+1][j]>res[i][j]+1) 
            {
                res[i+1][j] = res[i][j]+1;
                qu.push(pair<int,int>(i+1,j));
            }
            if(j+1<n&&res[i][j+1]>res[i][j]+1) 
            {
                res[i][j+1] = res[i][j]+1;
                qu.push(pair<int,int>(i,j+1));
            }
        }
        return res;
    }
};
