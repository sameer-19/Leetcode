class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> d;
        
        while(k>0)
        {
            d.push_back(k%10);
            k/=10;
        }
        
        int m=d.size();
        reverse(num.begin(),num.end());
        vector<int> ans;
        
        int i=0,j=0,c=0;
        
        while(i<n and j<m)
        {
            int sum = num[i] + d[j] + c;
            ans.push_back(sum%10);
            c = sum/10;
            i++;j++;
        }
        
        while(i<n)
        {
            int sum = num[i] + c;
            ans.push_back(sum%10);
            c=sum/10;
            i++;
        }
        
        while(j<m)
        {
            int sum = d[j] + c;
            ans.push_back(sum%10);
            c=sum/10;
            j++;
        }
        
        while(c>0)
        {
            ans.push_back(c%10);
            c/=10;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};