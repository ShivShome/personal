class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxi>=n-1) return true;
            if(i>maxi) return false;
            if(nums[i]+i>maxi){
                maxi=nums[i]+i;
            }
        }
        return false;
    }
};