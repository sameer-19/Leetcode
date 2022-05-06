class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans,tmp;
        
        int i,j,n=s.length();
        
        string st="";
        for(i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                tmp.push_back(st);
                st="";
            }
            else st+=s[i];
        }
        tmp.push_back(st);
        n=tmp.size();
        
        int mx=0;
        for(auto x: tmp) 
        {
            if(mx<x.size()) mx=x.size();
        }
        
        for(i=0;i<mx;i++)
        {
            string a="";
            for(j=0;j<n;j++)
            {
                if(tmp[j].size()>i) a+=tmp[j][i];
                else a+=' ';
            }
            ans.push_back(a);
        }
        for(i=0;i<mx;i++)
        {
            while(ans[i].size()>0 and ans[i][ans[i].size()-1]==' ') ans[i].pop_back();
        }
        
        return ans;
    }
};