class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        long long MOD=1e9+7;
        long long ans=0;
        
        int i,n=a.size();
        sort(a.begin(),a.end());
        
        for(i=0;i<=n-1;i++)
        {
            int front=i+1,back=n-1;
            int ttarget=target-a[i];
            
            while(front<back)
            {
                int sum=a[front]+a[back];
                if(sum>ttarget) back--;
                else if(sum<ttarget) front++;
                else if(a[front]!=a[back])
                {
                    vector<int> triplet={a[i],a[front],a[back]};
                    int c1=1,c2=1;
                    
                    while(front+1<back && a[front]==a[front+1]) { c1++;front++; }
                    while(back-1>front && a[back]==a[back-1]) { c2++;back--; }
                    
                    ans=(ans+(c1*c2))%MOD;
                    
                    front++;
                    back--;
                }
                else{
                    ans+=((back-front+1)*(back-front))/2;
                    ans%=MOD;
                    break;
                }
            }
        }
        return (int)ans;   
    }
};