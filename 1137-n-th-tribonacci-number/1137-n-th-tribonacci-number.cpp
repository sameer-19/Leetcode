class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        int i,a[40];
        a[0]=0;a[1]=1;a[2]=1;
        for(i=3;i<=n;i++) a[i]=a[i-1]+a[i-2]+a[i-3];
        return a[n];
    }
};