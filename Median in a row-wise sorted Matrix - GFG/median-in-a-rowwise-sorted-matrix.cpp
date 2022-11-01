//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numsLessThanMid(vector<int> &a,int n,int mid)
    {
        int cnt=0;
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int m = (left+right)/2;
            if(a[m]<=mid) left=m+1;
            else right=m-1;
        }
        
        return left;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int low=1,high=2001;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int cnt=0;
            for(int i=0;i<R;i++)
            {
                cnt+=numsLessThanMid(matrix[i],C,mid);
            }
            
            if(cnt<=(R*C)/2) low=mid+1;
            else high=mid-1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends