class Solution {
public:
    string solve(int x,int k)
    {
        string s(k,'0');
        int c=k-1;
        
        while(x>0)
        {
            int rem=x%2;
            if(rem==1) s[c]='1';
            else s[c]='0';
            x/=2;
            c--;
        }
        return s;
    }
    
    bool hasAllCodes(string s, int k) {
        map<string,int> mp;
        
        string st="";
        int i,n=s.length();
        
        if(k>n) return false;
        
        for(i=0;i<k;i++) st+=s[i];
        
        mp[st]++;
        
        for(i=k;i<n;i++)
        {
            st.erase(st.begin());
            st+=s[i];
            mp[st]++;
        }
        
        for(i=0;i<(1<<k);i++)
        {
            string res=solve(i,k);
            // cout<<res<<" ";
            
            if(mp[res]==0) return false; 
        }
        return true;
    }
};