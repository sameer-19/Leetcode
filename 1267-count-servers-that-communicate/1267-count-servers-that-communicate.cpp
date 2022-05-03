class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            int x=-1,y=-1;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(x==-1 && y==-1){
                        x=i; y=j;
                    }
                    else{
                        grid[x][y]=2;
                        grid[i][j]=2;
                    }
                }
            }
        }
        
        
            
        for(int j=0;j<grid[0].size();j++){
           int x=-1,y=-1;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]!=0){
                    if(x==-1 && y==-1){
                        x=i; y=j;
                    }
                    else{
                        grid[x][y]=2;
                        grid[i][j]=2;
                    }
                }
            }
        }
                               
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                               if(grid[i][j]==2)
                                    cnt++;
        
        return cnt;
    }
};