class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int i = 0;
        
        vector<int> incoming(n,0);
        
        for(auto x: edges)
        {
            incoming[x[1]]++;
        }
        
        vector<int> temp;
        
        while(i<n)
        {
            if(incoming[i]==0) temp.push_back(i);
            i++;
        }
        
        if(temp.size()==1) return temp[0];
        
        return -1;
    }
};