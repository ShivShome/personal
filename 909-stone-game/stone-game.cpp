class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& piles, int i, int j) {
        if (i > j) {
            return 0;
        }

        // Return memoized result if already calculated
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int left = piles[i]-solve(dp,piles,i+1,j);
        int right = piles[j]-solve(dp,piles,i,j-1);

        return dp[i][j] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        if (n <= 1) return true;

        return !(dp[0][0]);
    }
};