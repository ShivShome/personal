class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>dp(n,-1);
        int mini=prices[0];
        dp[0]=0;
        for(int i=1;i<n;i++){
           
            mini=min(mini,prices[i]);
            int left=dp[i-1];
            int right=prices[i]-mini;

            dp[i]=max(left,right);
        }
        return dp[n-1];
    }
};