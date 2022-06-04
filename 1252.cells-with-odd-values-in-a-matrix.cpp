class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int res = 0;
        bool* row = new bool[n];
        bool* col = new bool[m];
        memset(row,false,n*sizeof(bool));
        memset(col,false,m*sizeof(bool));
        for(int i=0;i<indices.size();++i)
        {
            row[indices[i][0]] = !row[indices[i][0]];
            col[indices[i][1]] = !col[indices[i][1]];
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(row[i]!=col[j]) res++;
            }
        }
        delete[] row;
        delete[] col;
        return res;
    }
};
