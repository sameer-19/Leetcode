class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0,c=0;
        while(i<word1.length() and j<word2.length())
        {
            if(c%2==0)
            {
                ans+=word1[i++];
            }
            else
            {
                ans+=word2[j++];
            }
            c++;
        }
        
        while(i<word1.length())
        {
            ans+=word1[i++];
        }
        
        while(j<word2.length())
        {
            ans+=word2[j++];
        }
        
        return ans;
    }
};