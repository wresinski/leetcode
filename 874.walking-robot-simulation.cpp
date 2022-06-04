class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int dx[4] = {0,1,0,-1};
        const int dy[4] = {1,0,-1,0};
        int dir = 0;
        int loc[2] = {0,0};
        int max = 0;
        int to[2];
        for(int i=0;i<commands.size();++i)
        {
            if(commands[i]==-2)
            {
                if(--dir<0) dir += 4;
            }
            else if(commands[i]==-1)
            {
                if(++dir>3) dir -= 4;
            }
            else if(commands[i]>=1&&commands[i]<=9)
            {
                to[0] = loc[0]+dx[dir]*commands[i];
                to[1] = loc[1]+dy[dir]*commands[i];
                cal(loc,to,obstacles);
                int dis = loc[0]*loc[0]+loc[1]*loc[1];
                if(dis>max) max = dis;
            }
        }
        return max;
    }
    void cal(int* from,int* to,vector<vector<int>> &obstacles)
    {
        if(from[0]==to[0])
        {
            int temp = to[1];
            for(int i=0;i<obstacles.size();++i)
            {
                if((from[0]==obstacles[i][0])&&(from[1]!=obstacles[i][1])&&(from[1]-obstacles[i][1])*(to[1]-obstacles[i][1])<=0)
                {
                    int newstep = to[1]>from[1]?obstacles[i][1]-1:obstacles[i][1]+1;
                    temp = abs(temp-from[1])<abs(newstep-from[1])?temp:newstep;
                }
            
            }
            from[1] = temp;
        }
        if(from[1]==to[1])
        {
            int temp = to[0];
            for(int i=0;i<obstacles.size();++i)
            {
                if((from[1]==obstacles[i][1])&&(from[0]!=obstacles[i][0])&&(from[0]-obstacles[i][0])*(to[0]-obstacles[i][0])<=0)
                {
                    int newstep = to[0]>from[0]?obstacles[i][0]-1:obstacles[i][0]+1;
                    temp = abs(temp-from[0])<abs(newstep-from[0])?temp:newstep;
                }
            }
            from[0] = temp;
        }
    }
};
