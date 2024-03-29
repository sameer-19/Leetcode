class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        int i,j;
        
        vector<bool> visited(n,false);
        
        queue<int> q;
        
        visited[0]=true;
        for(i=0;i<rooms[0].size();i++) 
        {
            if(!visited[rooms[0][i]]) q.push(rooms[0][i]);
        }
        
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            visited[tp]=true;
            
            for(auto x: rooms[tp])
            {
                if(!visited[x]) q.push(x);
            }
        }
        
        for(i=1;i<n;i++)
        {
            if(!visited[i]) return false;
        }
        
        return true;
        
    }
};