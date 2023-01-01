class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        int n=s.length(),i,j;
        string c="";
        for(i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                v.push_back(c);
                c="";
            }
            else c+=s[i];
        }
        
        if(c.length()>0) v.push_back(c);
        
        map<char,set<string>> mp;
        
        if(v.size()!=p.size()) return false;
        for(i=0;i<v.size();i++)
        {
            mp[p[i]].insert(v[i]);
        }
        
        for(auto x: mp)
        {
            if(x.second.size()>=2) return false;
        }
        
        map<string,set<char>> ch;
        for(i=0;i<v.size();i++)
        {
            ch[v[i]].insert(p[i]);
        }
        
        for(auto x: ch)
        {
            if(x.second.size()>=2) return false;
        }
        
        return true;
    }
};