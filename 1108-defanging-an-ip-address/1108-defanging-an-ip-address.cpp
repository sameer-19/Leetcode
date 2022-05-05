class Solution {
public:
    string defangIPaddr(string add) {
        string ans="";
        
        int i,n=add.size();
        
        for(i=0;i<n;i++)
        {
            if(add[i]!='.') ans+=add[i];
            else
            {
                ans+="[.]";
            }
        }
        
        
        return ans;
    }
};