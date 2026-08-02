class Solution {
public:
    long long strength(long long a, long long b) {
        long long g = gcd(a, b);
        return (a / g) * (b / g);
    }

    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long temp = strength(nums[i], nums[j]);
                maxi = max(maxi, temp);
            }
        }

        return maxi;
    }
};