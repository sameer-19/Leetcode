//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        
        string res="";
        
        for(int i=0;i<s.length();i++)
        {
            res+=s[i];
            
            set<string> v;
            
            for(int j=0;j<n;j++)
            {
                int k=0,l=0;
                while(k<contact[j].length() and l<res.length())
                {
                    if(res[l]==contact[j][k]) 
                    {
                        l++;
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(l==res.length()) v.insert(contact[j]);
            }
            
            // sort(v.begin(),v.end());
            vector<string> tmp(v.begin(),v.end());
            
            if(tmp.size()>0) ans.push_back(tmp);
            else ans.push_back({"0"});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends