class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]>b[0]) return true;
        else if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        
        return false;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        // sort by decreasing attack, increasing defence
        sort(a.begin(),a.end(),cmp);
        
        int ans=0,n=a.size(),max_d=0;
        
        for(int i=0;i<n;i++)
        {
            if(max_d>a[i][1])
            {
                ans++;
            }
            max_d=max(max_d,a[i][1]);
        }
        
        return ans;
    }
};