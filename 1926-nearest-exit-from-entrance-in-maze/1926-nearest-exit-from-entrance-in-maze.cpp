class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        int row = entrance[0],col = entrance[1];
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        int ans = INT_MAX;
        
        queue<vector<int>> q;
        
        visited[row][col] = true;
        
        if(row+1<m) 
        {
            if(maze[row+1][col]=='.') 
            {
                visited[row+1][col] = true;
                q.push({row+1,col,1});
            }
        }
        if(row-1>=0)
        {
            if(maze[row-1][col]=='.') 
            {
                q.push({row-1,col,1});
                visited[row-1][col] = true;
            }
        }
        if(col+1<n) 
        {
            if(maze[row][col+1]=='.') 
            {
                q.push({row,col+1,1});
                visited[row][col+1] = true;
            }
        }
        if(col-1>=0) 
        {
            if(maze[row][col-1]=='.') 
            {
                q.push({row,col-1,1});
                visited[row][col-1] = true;
            }
        }
        
        while(!q.empty())
        {
            vector<int> p = q.front();
            q.pop();
            
            int prevR = p[0],prevC = p[1], prevD = p[2];
            
            int f=0;
            
            if(prevR+1<m)
            {
                if(!visited[prevR+1][prevC] and maze[prevR+1][prevC]=='.')
                {
                    visited[prevR+1][prevC] = true;
                    q.push({prevR+1,prevC,prevD+1});
                }
            }
            else f=1;
            
            if(prevR-1>=0)
            {
                if(!visited[prevR-1][prevC] and maze[prevR-1][prevC]=='.') 
                {
                    visited[prevR-1][prevC] = true;
                    q.push({prevR-1,prevC,prevD+1});
                }
            }
            else f=1;
            
            if(prevC+1<n) 
            {
                if(!visited[prevR][prevC+1] and maze[prevR][prevC+1]=='.') 
                {
                    visited[prevR][prevC+1] = true;
                    q.push({prevR,prevC+1,prevD+1});
                }
            }
            else f=1;
            
            if(prevC-1>=0) 
            {
                if(!visited[prevR][prevC-1] and maze[prevR][prevC-1]=='.') 
                {
                    visited[prevR][prevC-1] = true;
                    q.push({prevR,prevC-1,prevD+1});
                }
            }
            else f=1;
            
            if(f==1) 
            {
                ans=prevD;
                break;
            }
        }
        
        if(ans!=INT_MAX) return ans;
        return -1;
    }
};