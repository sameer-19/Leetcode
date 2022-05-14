// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&mat){
    int ans=0;
    
    int mx=-1,i,j,m=mat.size(),n=mat[0].size();
    
    for(j=0;j<n;j++) ans=max(ans,mat[0][j]);
    
    for(i=1;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            int f=0,sum=0;
            if(j-1>=0)
            {
                if(mat[i-1][j-1]>=0) 
                {
                    f=1;
                    sum=mat[i-1][j-1];
                }
            }
            
            if(j+1<n)
            {
                if(mat[i-1][j+1]>=0) 
                {
                    f=1;
                    sum=max(sum,mat[i-1][j+1]);
                }
            }
            
            if(mat[i-1][j]>=0)
            {
                f=1;
                sum=max(sum,mat[i-1][j]);
            }
            
            if(f==0) mat[i][j]=-1;
            else
            {
                if(mat[i][j]>=0) mat[i][j]+=sum;    
                ans=max(ans,mat[i][j]);
            }
            
        }
    }
    
    for(j=0;j<n;j++)
    {
        mx=max(mx,mat[m-1][j]);
    }
    ans=max(ans,mx);
    
    // for(i=0;i<m;i++)
    // {
    //     for(j=0;j<n;j++) cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
    
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends