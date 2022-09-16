class Solution {
public:
    bool check(int row,int col,vector<vector<char>> &board,char ch)
    {   
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch) return false;
            if(board[row][i]==ch) return false;
            
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>> &board)
    {
        int n=board.size();
        
        int i,j;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(check(i,j,board,ch))
                        {
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
        return;
    }
};