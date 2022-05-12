// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size() ;
        int start_x , start_y ;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    {
                        start_x = i ; start_y = j ;
                    }
            }
        }
        
        queue<pair<int,int>> q ;
        
        q.push({start_x,start_y}) ;
        grid[start_x][start_y]*=-1 ;
        
        int dir[5] = {1,0,-1,0,1} ;
        
        while(!q.empty())
        {
            int x = q.front().first , y = q.front().second ; q.pop() ;
            
            if(grid[x][y]==-2)
                return true ;
            
            for(int i=0;i<4;i++)
            {
                int next_x = x+dir[i] ; 
                int next_y = y+dir[i+1] ;
                
                if(next_x>=0 && next_x<n && next_y>=0 && next_y<n && grid[next_x][next_y]>0)
                {
                    q.push({next_x,next_y}) ;
                    grid[next_x][next_y]*=-1 ;
                }
            }
        }
        
        return false;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends