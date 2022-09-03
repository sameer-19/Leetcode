class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector < int>> ans;

            sort(nums.begin(), nums.end());

            int i, j, k, n = nums.size();

            for (i = 0; i < n; i++)
            {
                int left = i + 1, right = n - 1;
                int leftSum = -nums[i];
                
                if(i>0)
                {
                    if(nums[i]==nums[i-1]) continue;
                }
                
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum == leftSum)
                    {
                        ans.push_back({ nums[i],
                            nums[left],
                            nums[right] });
                        int cur = nums[left];
                        while (left < right and nums[left] == cur) left++;

                        cur = nums[right];
                        while (left < right and nums[right] == cur) right--;
                    }
                    else if (sum > leftSum) right--;
                    else left++;
                }
            }

            return ans;
        }
};