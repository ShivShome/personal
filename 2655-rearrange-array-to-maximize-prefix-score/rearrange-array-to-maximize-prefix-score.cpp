class Solution {
public:
    int maxScore(vector<int>& nums) {
       sort(nums.rbegin(), nums.rend());
       long long sum=0;
       int count=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=1LL*nums[i];
        if(sum>0) count++;
       }
       return count;
    }
};