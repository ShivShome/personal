class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();

        int jumps=0;
        int curr=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,i+nums[i]);

            if(i == curr) {
                jumps++;
                curr = maxi;
            }

        }
        return jumps;
    }
};