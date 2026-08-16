class Solution {
public:
    int mini(vector<int> arr){
        int ans=INT_MAX;
        for(int i:arr) ans=min(ans,i);
        return ans;
    }

    int maxi(vector<int> arr){
        int ans=0;
        for(int i:arr) ans=max(ans,i);
        return ans;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        int i=0,j=1;

        while(j<n){
            int a=intervals[i][0];
            int b=intervals[i][1];
            int c=intervals[j][0];
            int d=intervals[j][1];

            if(b>=c){
                b=max(b,d);

                while(j+1<n && b>=intervals[j+1][0]){
                    j++;
                    b=max(b,intervals[j][1]);
                }

                ans.push_back({a,b});

                i=j+1;       // j was consumed
                j=i+1;
            }
            else{
                ans.push_back(intervals[i]);

                i=j;         // j was NOT consumed
                j=i+1;
            }
        }

        if(i<n)
            ans.push_back(intervals[i]);

        return ans;
    }
};