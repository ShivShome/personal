class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        int n=candies.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,candies[i]);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi) ans[i]=true;
            else ans[i]=false;
        }

        return ans;
    }
};