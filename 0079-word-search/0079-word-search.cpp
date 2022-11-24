class Solution {
public:
    bool solve(int idx,int i,int j,vector<vector<char>> &board,string 
&word,vector<vector<bool>> &visited)
    {
        if(idx==word.size())
        {
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(visited[i][j]) return false;
        
        visited[i][j]=true;
        bool take=false;
        
        int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
        if(board[i][j]==word[idx])
        {   
            for(int k=0;k<4;k++)
            {
                take |= solve(idx+1,dx[k]+i,dy[k]+j,board,word,visited);    
            }
            
            visited[i][j]=false;
            return take;
        }
        
        visited[i][j]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=word.size(),col=board[0].size();
        
        // cout<<col<<endl;
        int idx=0,i,j;
        vector<vector<bool>> visited(m,vector<bool> (col,false));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<col;j++)
            {
                if(!visited[i][j])
                {
                    if(solve(idx,i,j,board,word,visited)) return true;     
                }
            }
        }
        return false;
    }
};