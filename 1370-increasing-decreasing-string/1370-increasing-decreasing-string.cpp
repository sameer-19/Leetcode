class Solution {
public:
    char ch(int i)
    {
        char c='a';
        c+=i;
        return c;
    }
    
    string sortString(string s) {
        int n=s.length(),a[26]={0};
        
        int i;
        
        for(i=0;i<n;i++) a[s[i]-'a']++;
        
        string ans="";
        
        while(1)
        {
            bool f=0;
            
            for(i=0;i<26;i++)
            {
                if(a[i]>0)
                {
                    f=1;
                    ans+=ch(i);
                    a[i]--;
                }
            }
            for(i=25;i>=0;i--)
            {
                if(a[i]>0) 
                {
                    f=1; ans+=ch(i);
                    a[i]--;
                }
            }
            
            if(f==0) break;
        }
        
        return ans;
    }
};