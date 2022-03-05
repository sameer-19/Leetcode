// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int n, int m, vector<vector<int>> after){
        vector<vector<int>> ans(n,vector<int> (m,0));
        int i,j;
        ans[0][0]=after[0][0];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0 && j==0) continue;
                if(i==0) ans[i][j]=after[i][j]-after[i][j-1];
                else if(j==0) ans[i][j]=after[i][j]-after[i-1][j];
                else ans[i][j]=after[i][j]+after[i-1][j-1]- (after[i-1][j]+after[i][j-1]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends