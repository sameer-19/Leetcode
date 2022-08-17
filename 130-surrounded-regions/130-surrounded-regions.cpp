class Solution {
public:
    
    void dfs(int i,int j,int &n,int &m,vector<vector<char>> &board,vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(board[i][j]=='X') return;
        if(visited[i][j]) return;
        
        visited[i][j]=true;
        
        vector<vector<int>> moves = { {1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for(int k=0;k<4;k++)
        {
            int x=i+moves[k][0],y=j+moves[k][1];
            
            dfs(x,y,n,m,board,visited);
        }
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        
        int i,j,n=board.size(),m=board[0].size();

        vector<vector<bool>> visited(n+1,vector<bool> (m+1,false));
        
        if(board[0][0]=='O') visited[0][0]=true;
        if(board[0][m-1]=='O') visited[0][m-1]=true;
        if(board[n-1][0]=='O') visited[n-1][0]=true;
        if(board[n-1][m-1]=='O') visited[n-1][m-1]=true;
        
        for(i=1;i<m-1;i++)
        {
            if(board[0][i]=='O') // top
            {
                dfs(0,i,n,m,board,visited);
            }
            
            if(board[n-1][i]=='O') // bottom
            {
                dfs(n-1,i,n,m,board,visited);
            }
        }
        
        for(i=1;i<n-1;i++)
        {
            if(board[i][0]=='O') // left
            {
                dfs(i,0,n,m,board,visited);
            }
            
            if(board[i][m-1]=='O') // right
            {
                dfs(i,m-1,n,m,board,visited);
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(visited[i][j]==false) board[i][j]='X';
            }
        }
        
        return;
    }
};