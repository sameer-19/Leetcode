class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n=s.size();
        
        int i,j=0,ans=0;
        
        for(i=1;i<n;i++)
        {
            if(s[i]==s[i-1]) continue;
            else
            {
                
                if(i-j==1) 
                {
                    j=i;
                    continue;
                }
                
                int cnt=i-j;
                priority_queue<int> pq;
                
                for(int k=j;k<j+cnt;k++)
                {
                    pq.push(time[k]);
                }
                
                pq.pop();
                while(!pq.empty())
                {
                    ans+=pq.top();
                    pq.pop();
                }
                j=i;
            }
        }
        
        int cnt=i-j;
        priority_queue<int> pq;

        for(int k=j;k<j+cnt;k++)
        {
            pq.push(time[k]);
        }

        pq.pop();
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};