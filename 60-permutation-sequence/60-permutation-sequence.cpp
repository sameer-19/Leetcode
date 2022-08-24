class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        
        int i,cnt=1;
        
        for(i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        
        string ans="";
        
        while(cnt<k and next_permutation(v.begin(),v.end()))
        {
            cnt++;
            if(cnt==k) break;
        }
        
        for(i=0;i<n;i++)
        {
            ans+=to_string(v[i]);
        }
        
        return ans;
    }
};