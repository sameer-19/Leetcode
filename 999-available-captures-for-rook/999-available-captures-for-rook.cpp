class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n=8;
        int i,j;
        int x=-1,y=-1;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='R') 
                {
                    x=i;y=j;
                    break;
                }
            }
            if(x!=-1) break;
        }
        
        int ans=0;
        
        for(i=y-1;i>=0;i--)
        {
            if(board[x][i]=='.') continue;
            else if(board[x][i]=='B') break;
            else if(board[x][i]=='p') { ans++; break;}
        }
        
        for(i=y+1;i<n;i++)
        {
            if(board[x][i]=='.') continue;
            else if(board[x][i]=='B') break;
            else if(board[x][i]=='p') { ans++; break;}
        }
        
        for(i=x-1;i>=0;i--)
        {
            if(board[i][y]=='.') continue;
            else if(board[i][y]=='B') break;
            else if(board[i][y]=='p') { ans++; break;}
        }
        
        for(i=x+1;i<n;i++)
        {
            if(board[i][y]=='.') continue;
            else if(board[i][y]=='B') break;
            else if(board[i][y]=='p') { ans++; break;}
        }
        
        return ans;
    }
};