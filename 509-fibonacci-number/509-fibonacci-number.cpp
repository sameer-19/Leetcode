class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int i,a[31];
        a[0]=0;a[1]=1;
        for(i=2;i<=n;i++) a[i]=a[i-1]+a[i-2];
        return a[n];
    }
};