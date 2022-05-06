class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,set<char>> mp;
        
        int a[26]={0};
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            mp[s[i]].insert(t[i]);
        }
        for(auto x: mp)
        {
            if(x.second.size()>1) return false;
        }
        
        set<char> st;
        
        for(auto x: mp)
        {
            for(auto y: x.second)
            {
                if(st.find(y)==st.end())
                {
                    st.insert(y);
                }
                else return false;
            }
        }
        return true;
    }
};