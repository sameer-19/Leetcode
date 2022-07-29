class Cmp
{
public:
    bool operator() (pair<int,string> &a, pair<int,string> &b)
    {
        if(a.first>b.first) return true;
        else if(a.first==b.first) 
        {
            return (a.second<b.second);
        }
        return false;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
    priority_queue<pair<int,string>,vector<pair<int,string>>,Cmp> pq;
        
        vector<string> ans;
        
        map<string,int> mp;
        int n=words.size(),i,j;
        
        for(i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        
        for(auto x: mp)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)
            {
                pq.pop();   
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};