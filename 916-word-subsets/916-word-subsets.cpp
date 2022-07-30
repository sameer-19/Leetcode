class Solution {
public:
    bool check(string s1,vector<int> &v)
    {
        int a[26]={0},i,j;
        
        for(i=0;i<s1.length();i++) a[s1[i]-'a']++;
        
        for(i=0;i<26;i++)
        {
            if(v[i]>a[i]) return false;
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        
        int i,j,m=words1.size();
        
        vector<int> arr(26,0);
        for(i=0;i<words2.size();i++)
        {
            int b[26]={0};
            for(j=0;j<words2[i].length();j++) b[words2[i][j]-'a']++;
            
            for(j=0;j<26;j++)
            {
                arr[j]=max(arr[j],b[j]);
            }
            
        }
        
        for(i=0;i<m;i++)
        {
            if(check(words1[i],arr))
            {
                ans.push_back(words1[i]);
            }
        }
        
        return ans;
        
    }
};