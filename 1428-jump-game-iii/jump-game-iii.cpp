class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) mp[i] = 1;

            if(i + arr[i] < n)
                adj[i].push_back(i + arr[i]);

            if(i - arr[i] >= 0)
                adj[i].push_back(i - arr[i]);
        }

        queue<int> q;
        unordered_map<int,int> vis;

        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            if(mp.find(top) != mp.end())
                return true;

            for(int v : adj[top]){
                if(vis.find(v) == vis.end()){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return false;
    }
};