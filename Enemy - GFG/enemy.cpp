//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            
            if(k==0) return n*m;
            
            vector<int> row,col;
            
            for(auto x: enemy) 
            {
                row.push_back(x[0]);
                col.push_back(x[1]);
            }
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            
            int rmax=0,cmax=0;
            
            int prev=0;
            for(auto x: row) 
            {
                rmax=max(rmax,x-prev-1);
                prev=x;
            }
            rmax=max(rmax,n-prev);
            
            prev=0;
            for(auto x: col) 
            {
                cmax=max(cmax,x-prev-1);
                prev=x;
            }
            cmax=max(cmax,m-prev);
            
            return rmax*cmax;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends