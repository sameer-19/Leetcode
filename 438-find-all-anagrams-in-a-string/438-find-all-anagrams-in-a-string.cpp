class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        int m=s.length(),n=p.length(),i,j,flag=0;
        
        if(m<n) return ans;
        
        int a[26]={0},b[26]={0};
        
        for(i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        
        for(i=0;i<n;i++)
        {
            b[p[i]-'a']++;
        }
        
        for(i=0;i<26;i++){
            if(a[i]!=b[i])
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0) ans.push_back(0);
        
        for(i=n;i<m;i++){
            a[s[i-n]-'a']--;
            a[s[i]-'a']++;
            flag=0;
            for(j=0;j<26;j++)
            {
                if(a[j]!=b[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans.push_back(i-n+1);
        }
        
        return ans;
    }
};