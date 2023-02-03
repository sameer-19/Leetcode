class Solution {
public:
    string convert(string s, int nR) {
        vector<char> v[nR+1];
        
        if(nR==1) return s;
        
        string ans="";
        
        int cur = 1,i=0,flag=0;
        
        while(i<s.size())
        {
            v[cur].push_back(s[i]);
            if(flag==0)
            cur++;
            else cur--;
            
            if(cur==0) 
            {
                flag=0;
                cur=2;
            }
            else if(cur==nR+1)
            {
                flag=1;
                cur = nR-1; 
            }
            
            i++;
        }
        
        for(auto x: v)
        {
            for(auto y: x) ans+=y;
        }
        
        return ans;
    }
};