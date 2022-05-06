class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        int freq[26]={0};
        int i,j;
        
        for(i=0;i<words2.size();i++)
        {
            int a[26]={0};
            for(j=0;j<words2[i].size();j++) a[words2[i][j]-'a']++;
            for(j=0;j<26;j++) freq[j]=max(freq[j],a[j]);
        }
        
        for(i=0;i<words1.size();i++)
        {
            int a[26]={0},f=0;
            for(j=0;j<words1[i].size();j++) a[words1[i][j]-'a']++;
            
            for(j=0;j<26;j++)
            {
                if(a[j]<freq[j]) {f=1; break;}
            }
            if(f==0) ans.push_back(words1[i]);
            
        }
        
        return ans;
    }
};