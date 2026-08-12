class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l=0,r=0;
        int n=nums.size();
        int maxlen=0;

        while(r<n){
            // cout<<" Before l: " <<l<<" r "<< r<< " maxlen "<< maxlen;
            mp[nums[r]]++;
            // cout<<" here r  is "<<r<<" mp r is "<< mp[nums[r]];
          while(mp[nums[r]] > k) {
    mp[nums[l]]--;
    l++;
}

            maxlen=max(maxlen,r-l+1);
            r++;
            //  cout<<" After l: " <<l<<" r "<< r<< " maxlen "<< maxlen<<endl;
        }
        return maxlen;
    }
};