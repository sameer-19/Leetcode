class Solution
{
    public:
        vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;

            int n = nums.size(), i = 0;
            vector<int> ans(n, 0);

            for (auto &x: nums) pq.push({ x,
                i++ });

            while (k--)
            {
                int cur = pq.top().first;
                int idx = pq.top().second;
                pq.pop();
                pq.push({ cur *multiplier,
                    idx });
            }

            while (!pq.empty())
            {
                ans[pq.top().second] = pq.top().first;
                pq.pop();
            }

            return ans;
        }
};