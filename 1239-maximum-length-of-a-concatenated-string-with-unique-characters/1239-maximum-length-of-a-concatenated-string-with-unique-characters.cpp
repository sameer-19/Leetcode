class Solution {
public:
    int ans;
    
    bool unique(string s)
    {
        unordered_set<char> st(s.begin(),s.end());
        if(st.size()!=s.length()) return false;
        
        return true;
    }
    
    void solve(int idx,string s,vector<string> &arr)
    {
        if(!unique(s)) return;
        
        if(s.length()>ans) ans=s.length();
        
        for(int i=idx;i<arr.size();i++)
        {
            solve(i+1,s+arr[i],arr);
        }
    }
        
    int maxLength(vector<string>& arr) {
        ans=0;
        solve(0,"",arr);
        
        return ans;
    }
};