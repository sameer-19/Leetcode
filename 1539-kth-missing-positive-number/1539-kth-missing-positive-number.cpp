class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur=1,missing=0;
        int i=0,n=arr.size();
        
        while(i<n)
        {
            if(arr[i]<cur)
            {
                i++;
            }
            else if(arr[i]==cur)
            {
                cur++;
                i++;
            }
            else
            {
                missing++;
                if(missing==k) return cur;
                cur++;
            }
            
        }
        
        while(missing<k)
        {
            missing++;
            cur++;
        }
        
        return cur-1;
    }
};