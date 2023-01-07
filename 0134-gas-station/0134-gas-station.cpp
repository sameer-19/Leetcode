class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=gas[i]-cost[i];
        }
        
        if(sum>=0) 
        {
            int start=0,tank=0,total=0;
            for(int i=0;i<gas.size();i++)
            {
                tank=tank+gas[i]-cost[i];
                if(tank<0)
                {
                    start=i+1;
                    total+=tank;
                    tank=0;
                }
            }
            return total+tank<0 ? -1 : start;
        }
        else
        {
            return -1;
        }
        
    }
};