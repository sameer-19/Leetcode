class Solution {
public:
    string reverseWords(string s) {
        string ans="",str="";
        vector<string> v;
        
        int n=s.length(),i;
        
        for(i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(str.length()>0)
                {
                    v.push_back(str);
                    v.push_back(" ");
                    str="";
                }
            }
            else
            {
                str+=s[i];
            }
        }
        
        if(str.length()>0) v.push_back(str);
        
        i=v.size()-1;
        
        while(i>=0 and v[i]==" ") i--;
        
        while(i>=0)
        {
            ans+=v[i];
            i--;
        }
        
        return ans;
    }
};