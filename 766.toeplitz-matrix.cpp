class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(),N = matrix[0].size();
	for(int i=1;i<M;++i) {
	    for(int j=1;j<N;++j) {
		if(matrix[i][j]!=matrix[i-1][j-1]) return false;
	    }
	}
	return true;
	/*
        int M = matrix[0].size(),N = matrix.size();
        for(int i=0;i<M;++i)
        {
            int x = i,y = 0;
            while(x<M&&y<N)
            {
                if(matrix[y++][x++]!=matrix[0][i]) return false;
            }
        }
        for(int i=0;i<N;++i)
        {
            int x = 0,y = i;
            while(x<M&&y<N)
            {
                if(matrix[y++][x++]!=matrix[i][0]) return false;
            }
        }
        return true;
	*/
    }
};
