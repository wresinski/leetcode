class Solution {
public:
    /*
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int sizeX = grid.size();
        int sizeY = grid[0].size();
        int* set = new int[sizeX*sizeY];
        for(int i=0;i<sizeX;++i)
        {
            for(int j=0;j<sizeY;++j)
            {
                if(grid[i][j]=='1') 
                {
                    set[i*sizeY+j] = i*sizeY+j;
                    res++;
                }
            }
        }
         for(int i=0;i<sizeX;++i)
        {
            for(int j=0;j<sizeY;++j)
            {
                if(grid[i][j]=='1') 
                {
                    //if(i-1>=0&&grid[i-1][j]=='1') unite(i*sizeY+j,(i-1)*sizeY+j,set,res);
                    //if(j-1>=0&&grid[i][j-1]=='1') unite(i*sizeY+j,i*sizeY+(j-1),set,res);
                    if(i+1<sizeX&&grid[i+1][j]=='1') unite(i*sizeY+j,(i+1)*sizeY+j,set,res);
                    if(j+1<sizeY&&grid[i][j+1]=='1') unite(i*sizeY+j,i*sizeY+j+1,set,res);
                }
            }
        }
        delete[] set;
        return res;
    }

    int find(int i, int* set)
    {
        if(set[i]!=i) set[i] = find(set[i],set);
        return set[i];
    }

    void unite(int u1, int u2, int* set, int &count)
    {
        u1 = find(u1,set);
        u2 = find(u2,set);
        if(u1!=u2)
        {  
            set[u2] = u1;
            count--;
        }
    }
    */
    /*
    //DFS1
    int numIslands(vector<vector<char>>& grid) {
	int res = 0;
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	for (int i = 0; i < sizeX; ++i) {
	    for (int j = 0; j < sizeY; ++j) {
		if (grid[i][j] == '1') {
		    res++;
		    dfs(grid, i, j);
		}
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	stack<pair<int,int>> s;
	s.push(make_pair(i,j));
	while (!s.empty()) {
	    i = s.top().first;
	    j = s.top().second;
	    s.pop();
	    grid[i][j] = '0';
	    if (i > 0 && grid[i - 1][j] == '1')
		s.push(make_pair(i - 1, j));
            if (j > 0 && grid[i][j - 1] == '1')
                s.push(make_pair(i, j - 1));
	    if (i < sizeX - 1 && grid[i + 1][j] == '1')
                s.push(make_pair(i + 1, j));
            if (j < sizeY - 1 && grid[i][j + 1] == '1')
                s.push(make_pair(i, j + 1));
        }
    }
    */
    /*
    //DFS2
    int numIslands(vector<vector<char>>& grid) {
	int res = 0;
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	for (int i = 0; i < sizeX; ++i) {
	    for (int j = 0; j < sizeY; ++j) {
		if (grid[i][j] == '1') {
		    res++;
		    dfs(grid, i, j);
		}
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	grid[i][j] = '0';
	if (i > 0 && grid[i - 1][j] == '1')
	    dfs(grid, i - 1, j);
	if (j > 0 && grid[i][j - 1] == '1')
	    dfs(grid, i, j - 1);
	if (i < sizeX - 1 && grid[i + 1][j] == '1')
	    dfs(grid, i + 1, j);
	if (j < sizeY - 1 && grid[i][j + 1] == '1')
	    dfs(grid, i, j + 1);
    }
    */
    //BFS1
    int numIslands(vector<vector<char>>& grid) {
	int res = 0;
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	for (int i = 0; i < sizeX; ++i) {
	    for (int j = 0; j < sizeY; ++j) {
		if (grid[i][j] == '1') {
		    res++;
		    bfs(grid, i, j);
		}
            }
        }
        return res;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
	int sizeX = grid.size();
	int sizeY = grid[0].size();
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while (!q.empty()) {
	    i = q.front().first;
	    j = q.front().second;
	    q.pop();
	    //grid[i][j] = '0'; //不应该写在这里，不然会产生多次重复
	    if (i > 0 && grid[i - 1][j] == '1') {
		grid[i - 1][j] = '0';
		q.push(make_pair(i - 1, j));
	    }
	    if (j > 0 && grid[i][j - 1] == '1') {
		grid[i][j - 1] = '0';
		q.push(make_pair(i, j - 1));
	    }
	    if (i < sizeX - 1 && grid[i + 1][j] == '1') {
		grid[i + 1][j] = '0';
                q.push(make_pair(i + 1, j));
	    }
            if (j < sizeY - 1 && grid[i][j + 1] == '1') {
		grid[i][j + 1] = '0';
                q.push(make_pair(i, j + 1));
	    }
        }
    }
};
