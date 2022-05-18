// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(int idx,int n,string s,string res,vector<string>& ans)
    {
        if(idx==n)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx;i<n;i++)
        {
            res+=s[i];
            solve(i+1,n,s,res,ans);
            res.pop_back();
            res+=' ';res+=s[i];
            solve(i+1,n,s,res,ans);
        }
        
    }


    vector<string> permutation(string s){
        vector<string> ans;
        
        int n=s.length(),i,j;
        
        string res="";
        res+=s[0];
        
        solve(1,n,s,res,ans);
        set<string> st;
        for(auto x: ans) st.insert(x);
        
        ans.clear();
        for(auto x: st) ans.push_back(x);
        
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends