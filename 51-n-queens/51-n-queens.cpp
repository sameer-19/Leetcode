class Solution {
public:
    bool check(int row,int col,int n,vector<string> &res)
    {
        int r=row,c=col;
        c--;
        while(c>=0)
        {
            if(res[r][c]=='Q') return false;
            c--;
        }
        
        r=row;c=col;
        r--;c--;
        while(r>=0 and c>=0)
        {
            if(res[r][c]=='Q') return false;
            r--;c--;
        }
        
        r=row;c=col;
        r++;c--;
        while(r<n and c>=0)
        {
            if(res[r][c]=='Q') return false;
            r++;c--;
        }
        
        return true;
    }
    
    void solve(int col,int n,vector<string> &res,vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.push_back(res);
            return;
        }
        
        int row=0;
        
        while(row<n)
        {
            if(check(row,col,n,res))
            {
                res[row][col]='Q';
                solve(col+1,n,res,ans);
                res[row][col]='.';
            }   
            row++;
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n);
        
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        solve(0,n,board,ans);
        
        return ans;
    }
};