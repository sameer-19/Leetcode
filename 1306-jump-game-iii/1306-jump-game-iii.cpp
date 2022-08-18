class Solution {
public:
    
    bool solve(int i,vector<int>&arr,int n,vector<bool>&visited)
    {
        if(i<0 || i>=n) return false;
        
        if(arr[i]==0) return true;
        if(visited[i]) return false;
        
        visited[i]=true;
        
        if(solve(i+arr[i],arr,n,visited) || solve(i-arr[i],arr,n,visited)) return true;
        
        return false;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        
        if(arr[start]==0) return true;
        vector<bool> visited(arr.size()+1,false);
        
        return solve(start,arr,arr.size(),visited);
    }
};