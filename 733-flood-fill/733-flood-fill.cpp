class Solution {
public:
    void solve(int row,int col,vector<vector<bool>> &visited,
               vector<vector<int>> &image,vector<vector<int>> &ans,int newcolor,int color)
    {
        int m=image.size(),n=image[0].size();
        
        visited[row][col]=true;
        ans[row][col]=newcolor;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !visited[nrow][ncol] and image[nrow][ncol]==color) 
            {
                solve(nrow,ncol,visited,image,ans,newcolor,color);
            }
        }
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size(),i,j;
        
        vector<vector<int>> ans=image;
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        solve(sr,sc,visited,image,ans,color,image[sr][sc]);
        
        return ans;
        // int m=image.size(),n=image[0].size(),i,j;
        
//         queue<pair<int,int>> q;
        
//         vector<vector<bool>> visited(m,vector<bool> (n,false));
        
//         q.push({sr,sc});
        
//         while(!q.empty())
//         {
//             pair<int,int> p=q.front();
//             q.pop();
//             visited[p.first][p.second]=true;
            
//             int dx[4]={0,0,1,-1};
//             int dy[4]={1,-1,0,0};
            
//             for(i=0;i<4;i++)
//             {
//                 int x=p.first+dx[i];
//                 int y=p.second+dy[i];
//                 if(x>=0 and x<m and y>=0 and y<n)
//                 {
//                     if(!visited[x][y])
//                     {
//                         if(image[x][y]==image[sr][sc])
//                         {
//                             image[x][y]=color;
//                             q.push({x,y});
//                         }
//                     }
//                 }
//             }
//         }
        
//         image[sr][sc]=color;
        
//         return image;
    }
};