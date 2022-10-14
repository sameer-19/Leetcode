//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job &a,Job &b)
    {
        if(a.profit>b.profit) return true;
        return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        
        sort(arr,arr+n,cmp);
        
        int maxDeadLine = 0;
        
        for(int i=0;i<n;i++) maxDeadLine = max(maxDeadLine,arr[i].dead);
        
        vector<int> deadline(maxDeadLine+1,0);
        
        long total=0,cnt=0;
        
        for(int i=0;i<n;i++)
        {
            int d=arr[i].dead;
            // int profit = arr[i].profit;
            
            while(d>=1 and deadline[d]!=0)
            {
                d--;
            }
            
            if(d!=0 and deadline[d]==0)
            {
                cnt++;
                total+=arr[i].profit;
                deadline[d]=arr[i].id;
            }
        }
        
        ans.push_back(cnt);
        ans.push_back(total);
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends