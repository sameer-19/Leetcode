class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int> mp;
        
        for(auto x: bank) mp[x]++;
        
        queue<string> q;
        
        int ans=-1,cnt=0;
        
        q.push(start);
        
        while(!q.empty())
        {
            cnt++;
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                string s = q.front();
                q.pop();
                
                if(end==s)
                {
                    ans=cnt;
                    break;
                }
                
                string tmp=s;
                for(int j=0;j<s.length();j++)
                {
                    for(int k=0;k<26;k++)
                    {
                        char ch = 'A';
                        ch+=k;
                        tmp[j]=ch;
                        
                        if(mp.find(tmp)!=mp.end())
                        {
                            mp[tmp]--;
                            q.push(tmp);
                            
                            if(mp[tmp]==0) mp.erase(tmp);
                        }
                    }
                    
                    tmp=s;
                }
            }
            
            if(ans!=-1) break;
        }
        
        if(ans!=-1) return ans-1;
        else return -1;
    }
};