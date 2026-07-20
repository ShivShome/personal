class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int count = 0, l = 0, r = 0, n = nums.size();
        long long curr = 1;

        while(r < n){
            curr *= nums[r];

            if(curr < k)
                count += (r - l + 1);
            else{
                while(curr >= k){
                    curr /= nums[l];
                    l++;
                }
                count += (r - l + 1);
            }
            r++;
        }
        return count;
    }
};