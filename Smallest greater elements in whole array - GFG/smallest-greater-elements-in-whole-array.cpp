// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int a[], int n)
{
    set<int> s;
    int i;
    for(i=0;i<n;i++) s.insert(a[i]);
    for(i=0;i<n;i++)
    {
        auto x = s.upper_bound(a[i]);
        if(x!=s.end())
        {
            a[i]=(*x);
        }
        else a[i]=(-10000000);
    }
    
    return a;
    
}
