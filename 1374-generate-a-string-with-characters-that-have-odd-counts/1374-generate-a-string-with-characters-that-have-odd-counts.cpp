class Solution {
public:
    string generateTheString(int n) {
        string ans="";
        
        if(n%2==0)
        {
            ans+='a';
            for(int i=0;i<n-1;i++) ans+='b';
            return ans;
        }
        else
        {
            ans+='a';
            if(n>1)
            ans+='b';
            for(int i=0;i<n-2;i++) ans+='c';
            return ans;
        }
    }
};