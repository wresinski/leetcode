class Solution {
public:
    /* 暴力法
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=grid.size()-1;i>=0;--i)
        {
            if(grid[i][grid[i].size()-1]<0) res++;
            else break;
            for(int j=grid[i].size()-2;j>=0;--j)
            {
                if(grid[i][j]<0) res++;
                else break;
            }
        }
        return res;
    }
    */

    /*二分查找*/
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();++i){
            int l = 0,r = grid[i].size()-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(grid[i][mid]<0) r = mid-1;
                else l = mid+1;
            }
            res += grid[i].size()-l;
        }
        return res;
    }
    /*分治*/
    int solve(int l, int r, int L, int R, vector<vector<int>> grid){
        return 0;
    }
};
