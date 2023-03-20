class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool possible = true;
        int cnt=0,sz=flowerbed.size();
        
        if(sz==1) 
        {
            if(flowerbed[0]==1 and n==1) return 0;
            return 1;
        }
        
        for(int i=0;i<sz;i++)
        {
            if(flowerbed[i]==0) 
            {
                int c=0;
                if(i+1<sz)
                {
                    if(flowerbed[i+1]==1) continue;
                    else 
                    {
                        if(i-1>=0)
                        {
                            if(flowerbed[i-1]==1) continue;
                            else 
                            {
                                c++;
                                flowerbed[i]=1;        
                            }
                        }
                        else 
                        {
                            c++;
                            flowerbed[i]=1;
                        }
                    }
                }
                
                if(i-1>=0)
                {
                    if(flowerbed[i-1]==1) continue;
                    else 
                    {
                        if(i+1<sz)
                        {
                            if(flowerbed[i+1]==1) continue;
                            else 
                            {
                                c++;
                                flowerbed[i]=1;        
                            }
                        }
                        else 
                        {
                            c++;
                            flowerbed[i]=1;
                        }
                    }
                }
                
                if(c>0) cnt++;
            }
        }
        
        return cnt>=n;
    }
};