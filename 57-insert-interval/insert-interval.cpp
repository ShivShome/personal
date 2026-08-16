class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0], end = newInterval[1];

        int n = intervals.size();

        int lb = 0, ub = 0;

        int i = 0;
        while(i < n && intervals[i][1] < start) i++;
        lb = i;

        i = 0;
        while(i < n && intervals[i][0] <= end) i++;
        ub = i - 1;

        int j = 0;
        while(j < lb) {
            ans.push_back(intervals[j]);
            j++;
        }

        if(lb <= ub) {
            start = min(start, intervals[lb][0]);
            end = max(end, intervals[ub][1]);
        }

        ans.push_back({start, end});

        j = ub + 1;
        while(j < n) {
            ans.push_back(intervals[j]);
            j++;
        }

        return ans;
    }
};