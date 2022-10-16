//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination) {
        queue<pair<pair<int,int>,int>> q;
        // stores { {row,col}, distance} in the queue
        q.push({{src.first,src.second},0});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        
        visited[src.first][src.second]=1;
        
        int ans=-1;
        
        while(!q.empty())
        {
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;
            int distance = p.second;
            
            if(row==destination.first and col==destination.second)
            {
                ans=distance;
                break;
            }
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + dx[k];
                int ncol = col + dy[k];
                int d = 1+distance;
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited[nrow][ncol] and grid[nrow][ncol])
                {
                    q.push({{nrow,ncol},d});
                    visited[nrow][ncol]=1;
                }
            }
        }
        
       return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends