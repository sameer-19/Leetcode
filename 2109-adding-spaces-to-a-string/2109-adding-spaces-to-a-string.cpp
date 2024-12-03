class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        map<int,int> mp;
        
        for(auto &x: spaces)
        {
            mp[x]++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(i)!=mp.end())
            {
                ans+=' ';
            }
            ans+=s[i];
        }
        
        return ans;
    }
};