class Solution {
public:
    string reorganizeString(string s) {
        
        priority_queue<pair<int,char>> pq;
        string ans="";
        
        int i,a[26]={0},n=s.length();
        
        for(i=0;i<n;i++) a[s[i]-'a']++;
        
        for(i=0;i<26;i++) 
        {
            char ch='a';
            ch+=i;
            if(a[i]>0)
            pq.push({a[i],ch});
        }
        
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        
        while(!pq.empty())
        {
            pair<int,char> p=pq.top();
            pq.pop();
            if(ans.size()==0) 
            {
                ans+=p.second;
                p.first--;
                // cout<<p.first<<" "<<p.second<<endl;
                if(p.first>0) pq.push(p);
            }
            else{
                if(p.second==ans[ans.size()-1])
                {
                    if(!pq.empty())
                    {
                        pair<int,char> q=pq.top();
                        pq.pop();
                        ans+=q.second;
                        q.first--;
                        // cout<<q.first<<" "<<q.second<<endl;
                        if(q.first>0) pq.push(q);
                        if(p.first>0) pq.push(p);
                    }
                    else return "";
                }
                else
                {
                    ans+=p.second;
                    p.first--;
                    // cout<<p.first<<" "<<p.second<<endl;
                    if(p.first>0) pq.push(p);
                }
            }
        }
        
        return ans;
    }
};