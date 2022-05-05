class Solution {
public:
    bool judgeCircle(string move) {
        int x=0,y=0;
        
        int n=move.length(),i;
        
        for(i=0;i<n;i++)
        {
            if(move[i]=='U') y++;
            else if(move[i]=='D') y--;
            else if(move[i]=='L') x--;
            else x++;
        }
        
        return (x==0 and y==0);
    }
};