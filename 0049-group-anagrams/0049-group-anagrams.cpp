class Solution {
public:
    vector<int> solve(string s)
    {
        vector<int> ans(26,0);
        for(int i=0;i<s.length();i++)
        {
            ans[s[i]-'a']++;
        }
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        map<vector<int>,vector<string>> mp;
    
        for(int i=0;i<strs.size();i++)
        {
            vector<int> res= solve(strs[i]);
            mp[res].push_back(strs[i]);
        }
        
        for(auto x: mp) 
        {
            result.push_back(x.second);
        }
        
        return result;
    }
};