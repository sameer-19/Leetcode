class Solution {
public:
    bool check(int i, int j, int k, string s)
    {
        while(i<=j and s[i]==s[j]) i++;
        return i>j;
    }
    
    bool solve(string s, int length)
    {
        cout<<length<<" ";
        int i = length-1;
        unordered_map<string, int> mp;
        
        while(i<s.size())
        {
            if(check(i-length+1, i, length, s)) 
            {
                mp[s.substr(i-length+1, length)]++;
            }
            i++;
        }
        
        for(auto x: mp)
        {
            if(x.second>=3)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int maximumLength(string s) {
        int ans = -1, n = s.length();
        
        int left = 1, right = n;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            bool res = solve(s, mid);
            
            if(res) 
            {
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        
        
        
//         for(auto x: mp)
//         {
//             if(x.second>=3)
//             {
//                 int strLength = x.first.length();
//                 ans = max(ans, strLength);
//             }
//         }
        
        return ans;
    }
};