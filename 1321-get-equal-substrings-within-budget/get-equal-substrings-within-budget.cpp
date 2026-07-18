class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int l = 0, r = 0;
        int maxi = 0;
        int curr = 0;

        while (r < n) {
            int cost = abs(t[r] - s[r]);

            if (curr + cost <= maxCost) {
                curr += cost;
                r++;
            }
            else {
                while (curr + cost > maxCost) {   // FIX: maxCost
                    curr -= abs(t[l] - s[l]);     // FIX: subtract cost, not character
                    l++;
                }
                curr += cost;                     // FIX: include current character
                r++;                              // FIX: move right pointer
            }

            maxi = max(maxi, r - l);
        }

        return maxi;
    }
};