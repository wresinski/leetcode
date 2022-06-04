class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int sizeX = image.size();
	int sizeY = image[0].size();
	queue<pair<int,int>> q;
	if(image[sr][sc]==newColor) return image;
	int color = image[sr][sc];
	image[sr][sc] = newColor;
	q.push(make_pair(sr,sc));
	while (!q.empty()) {
	    int i = q.front().first;
	    int j = q.front().second;
	    q.pop();
	    if(i>0&&image[i-1][j]==color) {
		image[i-1][j] = newColor;
		q.push(make_pair(i-1,j));
	    }
	    if(j>0&&image[i][j-1]==color) {
		image[i][j-1] = newColor;
		q.push(make_pair(i,j-1));
	    }
	    if(i<sizeX-1&&image[i+1][j]==color) {
		image[i+1][j] = newColor;
		q.push(make_pair(i+1,j));
	    }
	    if(j<sizeY-1&&image[i][j+1]==color) {
		image[i][j+1] = newColor;
		q.push(make_pair(i,j+1));
	    }
	}
	return image;
    }
    /*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<vector<int>> q;
        vector<int> v;
        v.push_back(sr);v.push_back(sc);
        q.push(v);
        int color = image[sr][sc];
        if(color == newColor) return image;
        image[sr][sc] = newColor;
        while(!q.empty())
        {
            vector<int> current = q.front();
            q.pop();
            if(current[0]-1>=0&&image[current[0]-1][current[1]]==color)
            {
                image[current[0]-1][current[1]] = newColor;
                vector<int> v;
                v.push_back(current[0]-1);
                v.push_back(current[1]);
                q.push(v);
            }
            if(current[1]-1>=0&&image[current[0]][current[1]-1]==color)
            {
                image[current[0]][current[1]-1] = newColor;
                vector<int> v;
                v.push_back(current[0]);
                v.push_back(current[1]-1);
                q.push(v);
            }
            if(current[0]+1<image.size()&&image[current[0]+1][current[1]]==color)
            {
                image[current[0]+1][current[1]] = newColor;
                vector<int> v;
                v.push_back(current[0]+1);
                v.push_back(current[1]);
                q.push(v);
            }
            if(current[1]+1<image[0].size()&&image[current[0]][current[1]+1]==color)
            {
                image[current[0]][current[1]+1] = newColor;
                vector<int> v;
                v.push_back(current[0]);
                v.push_back(current[1]+1);
                q.push(v);

            }
        }
        return image;
    }
    */
};
