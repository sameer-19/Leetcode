class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) // prices, beauty in increasing order
    {
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        
        return false;
    }
    
    int find_index(int price,vector<int> &prices) // finding less or equal price index
    {
        int size = prices.size();
        int left = 0, right = size-1;
        
        int idx = -1;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            if(prices[mid]>price)
            {
                right = mid-1;
            }
            else if(prices[mid]==price)
            {
                while(mid<size && prices[mid]==price) mid++;
                return mid-1;
            }
            else {
                idx = mid;
                left = mid+1;
            }
        }
        
        return idx;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), cmp); // sorting items
        
        vector<int> res, ans, prices;
        int mx = 0;
        
        for(auto x: items)
        {
            prices.push_back(x[0]); // to store the increasing price for searching
            mx = max(mx, x[1]); // find the maximum beauty
            res.push_back(mx); // to store the maximum beauty till given price
        }
        
        for(auto x: queries)
        {
            int idx = find_index(x, prices);
            
            if(idx<0 || idx>items.size())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(res[idx]);    
            }
        }
        
        return ans;
    }
};