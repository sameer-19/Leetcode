// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat){
        int i,j,x=0,y=0,n=mat.size(),m=mat[0].size();
        pair<int,int> p;
        bool left=0,right=1,up=0,down=0;
        while(x>=0 && y>=0 && x<n && y<m)
        {
            p.first=x;p.second=y;
            if(mat[x][y]==0) 
            {
                if(left) y--;
                else if(right) y++;
                else if(up) x--;
                else x++;
            }
            else 
            {
                mat[x][y]=0;
                if(left)
                {
                    left=0;up=1; x--;
                }
                else if(right) 
                {
                    right=0;down=1; x++;
                }
                else if(up) 
                {
                    up=0;right=1; y++;
                }
                else 
                {
                    down=0; left=1; y--;
                }
            }
        }
        return p;
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends