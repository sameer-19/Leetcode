class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        pair<int,int> p1,p2;
        
        p1.first = max(ax1,bx1);
        p1.second = max(ay1,by1);
        
        p2.first = min(ax2,bx2);
        p2.second = min(ay2,by2);
        
        int ans = abs(p1.first-p2.first)*abs(p1.second-p2.second);
        
        if(p1.first>p2.first || p1.second>p2.second) ans=0;
        
        ans = (abs(ax2-ax1)*abs(ay2-ay1)) + (abs(bx2-bx1)*abs(by2-by1)) - ans; 
        
        return ans;
    }
};