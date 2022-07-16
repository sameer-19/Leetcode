class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,set<char>> mp,mp2;
        int i=0;
        
        for(auto x: s)
        {
            mp[x].insert(t[i++]);
        }
        
        i=0;
        for(auto x: t)
        {
            mp2[x].insert(s[i++]);
        }
        
        for(auto x: mp)
        {
            if(x.second.size()>1) return false;
        }
        
        for(auto x: mp2)
        {
            if(x.second.size()>1) return false;
        }
        
        return true;
    }
};