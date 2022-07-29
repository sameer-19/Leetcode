class Solution {
public:
    bool check(string a,string b)
    {
        map<char,char> mp1,mp2;
        int i,n=b.length();
        
        for(i=0;i<n;i++)
        {
            if(mp1.find(a[i])==mp1.end() and mp2.find(b[i])==mp2.end())
            {
                mp1[a[i]]=b[i];
                mp2[b[i]]=a[i];
            }
            else if(mp1[a[i]]!=b[i] || mp2[b[i]]!=a[i]) return false;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        int n=words.size(),i;
        
        for(i=0;i<n;i++)
        {
            if(check(words[i],pattern))
            {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};