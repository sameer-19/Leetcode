class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans="";
        
        int i,j=0,n=500,m=s.size();
        
        for(i=0;i<s.size();i++)
        {
            if(n>s[i].length()) n=s[i].length();
        }
            
        for(i=0;i<n;i++)
        {
            int cnt=1;
            j=1;
            while(j<m and s[j][i]==s[0][i]){ j++; cnt++; }
            
            if(cnt==m) ans+=s[0][i];
            else break;
        }
        
        return ans;
    }
};