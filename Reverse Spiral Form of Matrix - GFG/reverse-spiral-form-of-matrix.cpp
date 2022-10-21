//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&a)  {
        // code here
        vector<int> ans;
        int direction=1;
        int top = 0, left=0, right=m-1,bottom=n-1;
        
        while(top<=bottom and left<=right)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(a[top][i]);
                }
                
                top++;
                direction=2;
            }
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(a[i][right]);
                }
                
                right--;
                direction=3;
            }
            else if(direction==3)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(a[bottom][i]);
                }
                
                bottom--;
                direction=4;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(a[i][left]);
                }
                
                left++;
                direction=1;
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends