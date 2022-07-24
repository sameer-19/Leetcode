class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size(),i,j;
        
        queue<pair<int,int>> q;
        
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        q.push({sr,sc});
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            visited[p.first][p.second]=true;
            
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            
            for(i=0;i<4;i++)
            {
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(x>=0 and x<m and y>=0 and y<n)
                {
                    if(!visited[x][y])
                    {
                        if(image[x][y]==image[sr][sc])
                        {
                            image[x][y]=color;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        
        image[sr][sc]=color;
        
        return image;
    }
};