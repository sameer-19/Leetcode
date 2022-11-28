class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win,lose;
        
        int n=matches.size();
        
        vector<vector<int>> ans;
        vector<int> winners;
        vector<int> losers;
        
        for(int i=0;i<n;i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        
        for(auto x: win)
        {
            if(lose.find(x.first)==lose.end())
            {
                winners.push_back(x.first);
            }
        }
        
        for(auto x: lose)
        {
            if(x.second==1)
            {
                losers.push_back(x.first);
            }
        }
        
        ans.push_back(winners);
        ans.push_back(losers);
        
        return ans;
    }
};