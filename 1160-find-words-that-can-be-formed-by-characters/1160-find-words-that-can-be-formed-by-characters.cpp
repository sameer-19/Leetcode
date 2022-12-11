class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int a[26]={0};
        int ans=0;
        
        for(int i=0;i<chars.length();i++) a[chars[i]-'a']++;
        
        for(int i=0;i<words.size();i++)
        {
            int b[26]={0},flag=0;
            for(int j=0;j<words[i].size();j++) b[words[i][j]-'a']++;
            
            for(int j=0;j<26;j++)
            {
                if(b[j]>a[j]) {flag=1; break;}
            }
            
            if(flag==0) ans+=words[i].length();
        }
        
        return ans;
    }
};