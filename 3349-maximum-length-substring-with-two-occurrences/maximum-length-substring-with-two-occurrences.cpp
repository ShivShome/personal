class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0;
        int maxi=INT_MIN;

        int n=s.length();
        map<int,int> mp;

        while(r<n){
            mp[s[r]]++;
            while( mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);

            r++;
        }
        return maxi;
    }
};