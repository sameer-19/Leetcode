class Solution {
public:
    string reverseWords(string s) {
        int n=s.length(),i,j,k;
        
        for(i=0;i<n/2;i++) swap(s[i],s[n-i-1]);
        
        j=0;
        while(s[j]==' ') j++;
        
        int cnt=0;
        
        for(i=j;i<n;i++)
        {
            if(s[i]!=' ') cnt++;
            else
            {
                // cout<<i<<" ";
                for(k=0;k<(cnt/2);k++) swap(s[k+j],s[cnt+j-k-1]);
                cnt=1;
                
                while(i<n and s[i]==' ') i++;
                j=i;
            }
        }
        
        while(j<n and s[j]==' ') j++;
        for(k=0;k<(cnt/2) and k+j<n;k++) swap(s[k+j],s[cnt+j-k-1]);
        
        
        // cout<<s<<' ';
        string ans="";
        int f=0;
        
        i=0;
        while(i<n and s[i]==' ') i++;
        
        while(i<n)
        {
            if(s[i]!=' ') 
            {
                ans+=s[i];
                f=0;   
            }
            else
            {
                if(f==0) 
                {
                    f=1; 
                    ans+=s[i];
                } 
            }
            i++;
        }
        
        while(ans.back()==' ') ans.pop_back();
        
        return ans;
    }
};