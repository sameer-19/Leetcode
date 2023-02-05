class Solution {
public:
    bool check(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int a[26]={0},b[26]={0};
        
        int m=p.size(),n=s.size();
        
        if(n<m) return ans;
        
        for(int i=0;i<m;i++) b[p[i]-'a']++;
        
        for(int i=0;i<m;i++) a[s[i]-'a']++;
        
        if(check(a,b)) ans.push_back(0);
        
        for(int i=m;i<n;i++)
        {
            a[s[i]-'a']++;
            a[s[i-m]-'a']--;
            if(check(a,b)) ans.push_back(i-m+1);
        }
        
        return ans;
    }
};