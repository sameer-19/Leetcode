class Solution {
public:
    
    bool checkRow(int i,int j,vector<vector<char>>& board)
    {
        int n=9;
        
        for(int k=0;k<n;k++)
        {
            if(board[i][k]>='1' and board[i][k]<='9') 
            {
                if(k!=j)
                {
                    if(board[i][j]==board[i][k]) return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkCol(int i,int j,vector<vector<char>>& board)
    {
        int n=9;
        
        for(int k=0;k<n;k++)
        {
            if(board[k][j]>='1' and board[k][j]<='9') 
            {
                if(k!=i)
                {
                    if(board[i][j]==board[k][j]) return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkSquare(int i,int j,vector<vector<char>>& board)
    {
        int row = (i/3)*3;
        int col = (j/3)*3;
        
        for(int k=row;k<row+3;k++)
        {
            for(int l=col;l<col+3;l++)
            {
                if(k==i and l==j) continue;
                
                if(board[k][l]==board[i][j])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]>='1' and board[i][j]<='9')
                {
                    if(!checkRow(i,j,board)) return false;
                    if(!checkCol(i,j,board)) return false;
                    if(!checkSquare(i,j,board)) return false;
                }
            }
        }
        
        return true;
    }
};