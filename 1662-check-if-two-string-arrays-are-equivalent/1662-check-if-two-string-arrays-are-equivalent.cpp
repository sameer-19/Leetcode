class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        bool ok=true;
        int n=word1.size(),m=word2.size(),i,j;
        
        string s1="",s2="";
        
        for(i=0;i<n;i++)
        {
            s1+=word1[i];
        }
        
        for(i=0;i<m;i++)
        {
            s2+=word2[i];
        }
        
        return s1==s2;
    }
};