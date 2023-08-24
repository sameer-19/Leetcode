class Solution {
public:
    bool check(string ans)
    {
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]==ans[i-1]) return false;
        }
        return true;
    }
    
    string reorganizeString(string s) {
        int a[26]={0}; 
        
        string ans = "";
        
        for(auto x: s) a[x-'a']++;
        
        priority_queue<pair<int,char>> pq;
        
        for(int i=0;i<26;i++)
        {
            if(a[i]>0) pq.push({a[i],'a'+i});
        }
        
        while(pq.size()>1)
        {
            pair<int,char> f = pq.top();
            pq.pop();
            pair<int,char> s = pq.top();
            pq.pop();
            
            ans+=f.second;ans+=s.second;
            f.first--;
            s.first--;
            if(f.first>0)
            {
                pq.push(f);
            }
            
            if(s.first>0)
            {
                pq.push(s);
            }
        }
        
        while(!pq.empty())
        {
            pair<int,char> f = pq.top();
            pq.pop();
            
            ans+=f.second;
            f.first--;
            
            if(f.first>0)
            {
                pq.push(f);
            }
        }
        
        if(check(ans)) return ans;
        
        return "";
    }
};