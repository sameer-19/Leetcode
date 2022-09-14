class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        
        int i,j,ans=INT_MAX,lid=-1,rid=-1;
        
        map<char,int> a,b;
        
        for(i=0;i<m;i++)
        {
            a[t[i]]++;
        }
        
        int left=0,right=0;
        
        for(right=0;right<n;right++)
        {
            b[s[right]]++;
            int flag=0;
            for(auto c: a)
            {
                if(c.second>b[c.first])
                {
                    flag=1;break;
                }
            }
            if(flag) continue;
            
            if(ans>(right-left+1))
            {
                ans=right-left+1;
                lid=left;
                rid=right;
            }
            flag=0;
            while(left<=right)
            {
                b[s[left]]--;
                left++;
                for(auto c: a)
                {
                    if(c.second>b[c.first]) {flag=1; break;}
                }
                if(flag) break;
                
                if(ans>(right-left+1))
                {
                    ans=right-left+1;
                    lid=left;
                    rid=right;
                }
            }
        }
        
        if(lid==-1) return "";
        
        string result="";
        for(i=lid;i<=rid;i++) result+=s[i];
        
        return result;
    }
};