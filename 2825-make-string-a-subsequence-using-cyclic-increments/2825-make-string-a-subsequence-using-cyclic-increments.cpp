class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int len1 = str1.size(), len2 = str2.size();
        
        while(i<len1 and j<len2)
        {
            if(str1[i]==str2[j])
            {
                i++; j++;
            }
            else
            {
                if((str1[i]=='z' and str2[j]=='a') || (str1[i]+1==str2[j]))
                {
                    j++;
                }
                
                i++;
            }
        }
        
        if(j==len2) return true;
        return false;
    }
};