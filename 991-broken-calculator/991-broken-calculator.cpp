class Solution {
public:
    int brokenCalc(int sv, int tgt) {
        // if(sv==0) return INT_MAX-1;
        if(sv==tgt) return 0;
        if(sv>tgt) return sv-tgt;
        int ans=0;
        while(tgt!=sv)
        {
            ans++;
            if(tgt%2==0)
            {
                if(tgt>sv)
                {
                    tgt/=2;
                }
                else if(tgt<sv)
                {
                    ans--;
                    ans+=(sv-tgt);
                    break;
                }
            }
            else
            {
                if(tgt>sv)
                {
                    tgt++;
                }
                else
                {
                    ans--;
                    ans+=sv-tgt;
                    break;
                }
            }
        }
        return (int)ans;
    }
};