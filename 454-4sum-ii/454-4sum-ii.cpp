class Solution {
public:
    int fourSumCount(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4) {
        int n=num1.size();
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto x: num1)
        {
            for(auto y: num2)
            {
                mp[x+y]++;
            }
        }
        for(auto x: num3)
        {
            for(auto y: num4)
            {
                auto it=mp.find(0-x-y);
                if(it!=mp.end()) cnt+=it->second;
            }
        }
        return cnt;
    }
};