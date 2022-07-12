class Solution {
public:
    bool solve(int idx,int n,vector<int> &v,vector<int> &res)
    {
      if(idx==n)
      {
        if(res[0]==0 and res[1]==0 and res[2]==0 and res[3]==0) return true;
        return false;
      }
        
        for(int i=0;i<4;i++)
        {
            if(v[idx]<=res[i])
            {
                res[i]-=v[idx];
                if(solve(idx+1,n,v,res)) return true;
                res[i]+=v[idx];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& v) {
        
        int sum=0,j,i,n=v.size();
        
        if(n<4) return false;
        
        for(i=0;i<n;i++) sum+=v[i];
        if(sum%4!=0) return false;
        
        sum/=4;
        vector<int> res(4,sum);
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        return solve(0,n,v,res);
    }
};