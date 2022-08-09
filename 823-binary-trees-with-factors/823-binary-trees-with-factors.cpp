class Solution {
public:
    
    #define MOD 1000000007
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans=0,n=arr.size(),i,j;
        
        sort(arr.begin(),arr.end());
        
        unordered_map<long,long> mp;
        
        for(i=0;i<n;i++)
        {
            int cur_ans=1; // leaf node
            
            for(j=0;j<i;j++)
            {
                if(arr[i]%arr[j]) continue;
                
                int num1=arr[j];
                int num2=arr[i]/arr[j];
                
                cur_ans= (cur_ans + (mp[num1]*mp[num2])%MOD)%MOD;
            }
            
            mp[arr[i]]=cur_ans;
            
            ans=(ans+cur_ans)%MOD;
        }
        
        return ans;
    }
};