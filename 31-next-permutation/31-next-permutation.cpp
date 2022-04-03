class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size(),i,j;
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1]) break;
        }
        if(i<0)
        {
            reverse(a.begin(),a.end());
        }
        else{
            for(j=n-1;j>=0;j--)
            {
                if(a[j]>a[i]) break;
            }
            swap(a[j],a[i]);
            reverse(a.begin()+i+1,a.end());
        }
    }
};