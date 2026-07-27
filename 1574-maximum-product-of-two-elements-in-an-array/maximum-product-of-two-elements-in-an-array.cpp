class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int larg=0,slarg=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>larg){
                slarg=larg;
                larg=nums[i];
            }
            else if(nums[i]>slarg){
                slarg=nums[i];
            }
        }
    return (larg-1)*(slarg-1);
    }
};