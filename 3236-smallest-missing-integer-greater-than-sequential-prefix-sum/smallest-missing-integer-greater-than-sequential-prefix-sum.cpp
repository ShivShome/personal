class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i:nums) maxi=max(i,maxi);
        int n=nums.size();
        if(n==1) return nums[0]+1;
        unordered_set<int> sets(nums.begin(), nums.end()); 
        int curr=nums[0];
        int maxcurr=curr;
        for(int i=1;i<n;i++){
            // if(i==0){
            //     if(nums[1]==nums[0]+1) curr=nums[0];
                
            //     continue;
            // }
            if(nums[i]-nums[i-1]==1){
                curr+=nums[i];
                maxcurr=max(curr,maxcurr);
            }
            else{
                break;
            }
        }

        cout<< "maxi is"<<maxi<<"maxcurr is"<<maxcurr;
        if(maxi<maxcurr) return maxcurr;
        else if (maxi==maxcurr) return maxi+1;
        if(maxcurr==0) return maxi+1;
        for(int i=maxcurr;i<=maxi;i++){
            if(sets.find(i)==sets.end()) return i;
        }
        return maxi+1;
        // if(maxi>maxcurr) return maxi+1;
        // else return maxcurr;
    }
};