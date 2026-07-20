class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // stores indices
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing deque
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // First window completed
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};