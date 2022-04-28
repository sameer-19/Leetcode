// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    string print(int n)
    {
        int i;
        string st;
        for(i=1;i<=n;i++) st+=to_string(i);
        for(i=n-1;i>=1;i--) st+=to_string(i);
        // cout<<" ";
        return st;
    }

    vector<string> numberPattern(int n)
    {
        int i;
        vector<string> ans;
        for(i=1;i<=n;i++)
        {
            ans.push_back(print(i));
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
       
        Solution ob;
        vector<string> res = ob.numberPattern(N);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    
    }
    return 0;
}  // } Driver Code Ends