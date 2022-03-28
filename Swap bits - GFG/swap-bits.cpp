// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    void decimalToBinary(int a[],int n) {
        int i=0;
        while(n) {
            a[i]=n%2;
            n /= 2;
            i++;
        }
        return;
    }
    int binaryToDecimal(int a[]) {
        int ans = 0 , i = 0;
        while(i<32) {
            ans = ans + (a[i] == 1 ? (1ll << i) : 0);
            i++;
        }
        return ans;
    }

    int swapBits(int x, int p1, int p2, int n)
    {
        int i=0,arr[32]={0};
        decimalToBinary(arr,x);
        while(i<n)
        {
            swap(arr[p1],arr[p2]);
            p1++;p2++;
            i++;
        }
        int ans=binaryToDecimal(arr);
        return ans;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends