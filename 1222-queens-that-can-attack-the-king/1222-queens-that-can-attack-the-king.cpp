class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> a(8, vector<int> (8,0));
        
        int i,j;
        
        for(auto x: queens) 
        {
            a[x[0]][x[1]]=1;
        }
        a[king[0]][king[1]]=2;
        
        vector<vector<int>> ans;
        
        // left
        for(i=king[1]-1;i>=0;i--)
        {
            if(a[king[0]][i]==1)
            {
                ans.push_back({king[0],i});
                break;
            }
        }
        
        // right
        for(i=king[1]+1;i<8;i++)
        {
            if(a[king[0]][i]==1)
            {
                ans.push_back({king[0],i});
                break;
            }
        }
        
        // up
        for(i=king[0]-1;i>=0;i--)
        {
            if(a[i][king[1]]==1)
            {
                ans.push_back({i,king[1]});
                break;
            }
        }
        
        // down
        for(i=king[0]+1;i<8;i++)
        {
            if(a[i][king[1]]==1)
            {
                ans.push_back({i,king[1]});
                break;
            }
        }
        
        // left-up diagonal
        for(i=king[0]-1,j=king[1]-1;i>=0 && j>=0;i--,j--)
        {
            if(a[i][j]==1)
            {
                ans.push_back({i,j});
                break;
            }
        }
        
        // right-down diagonal
        for(i=king[0]+1,j=king[1]+1;i<8 && j<8;i++,j++)
        {
            if(a[i][j]==1)
            {
                ans.push_back({i,j});
                break;
            }
        }
        
        // left-down diagonal
        for(i=king[0]+1,j=king[1]-1;i<8 && j>=0;i++,j--)
        {
            if(a[i][j]==1)
            {
                ans.push_back({i,j});
                break;
            }
        }
        
        // right-up diagonal
        for(i=king[0]-1,j=king[1]+1;i>=0 && j<8;i--,j++)
        {
            if(a[i][j]==1)
            {
                ans.push_back({i,j});
                break;
            }
        }
        
        return ans;
    }
};