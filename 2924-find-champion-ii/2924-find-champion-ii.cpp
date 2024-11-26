class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int i = 0;
        
        vector<int> outgoing(n,0), incoming(n,0);
        
        for(auto x: edges)
        {
            outgoing[x[0]]++;
            incoming[x[1]]++;
        }
        
        vector<vector<int>> temp;
        
        while(i<n)
        {
            if(incoming[i]==0 and outgoing[i]>0) temp.push_back({i,outgoing[i]});
            else if(incoming[i]==0 and outgoing[i]==0) temp.push_back({i, outgoing[i]});
            i++;
        }
        
        if(temp.size()==1) return temp[0][0];
        
        return -1;
    }
};