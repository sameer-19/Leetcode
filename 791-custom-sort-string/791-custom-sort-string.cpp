class Solution {
public:
    
    string customSortString(string order, string s) {
        int a[26]={0},b[26]={0};
        
        int i,j,m=order.length(),n=s.length();
        
        for(i=0;i<m;i++){
            a[order[i]-'a']=i+1;
        }
        for(i=0;i<n;i++) b[s[i]-'a']++;
        
        vector<pair<int,char>> v;
        for(i=0;i<26;i++)
        {
            if(a[i]>0) v.push_back({a[i],i});
            else v.push_back({30+i,i});
        }
        
        sort(v.begin(),v.end());
        
        string ans="";
        for(i=0;i<26;i++)
        {
            char ch='a';
            ch+=v[i].second;
            for(j=0;j<b[v[i].second];j++) ans+=ch;
        }
        
        return ans;
    }
};