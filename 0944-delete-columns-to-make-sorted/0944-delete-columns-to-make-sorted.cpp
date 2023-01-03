class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int n=str.size();
        int m=str[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++)
        {
            int flag=0;
            for(int j=1;j<n;j++)
            {
                if(str[j][i]<str[j-1][i]) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag) ans++;
        }
        
        return ans;
    }
};