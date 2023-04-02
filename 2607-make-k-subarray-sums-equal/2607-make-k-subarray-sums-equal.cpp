class Solution
{
    public:
        long long makeSubKSumEqual(vector<int> &arr, int k)
        {
            long long sz = arr.size(), res = 0;
            
            for (int i = 0; i < k; ++i)
            {
                vector<int> cycle;
                
                for (int j = i; arr[j] != 0; j = (j + k) % sz)
                {
                    cycle.push_back(arr[j]);
                    arr[j] = 0;
                }
                
                nth_element(begin(cycle), begin(cycle) + cycle.size() / 2, end(cycle));
                
                for (int n: cycle)
                    res += abs(n - cycle[cycle.size() / 2]);
            }
            
            return res;
        }
};