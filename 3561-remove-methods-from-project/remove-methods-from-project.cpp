class Solution {
public:
// 0 not visited
// -1 suspicious
// 2 safe
// 3 conflict

    void DFS(vector<vector<int>>& adj, int idx, vector<int>& visited, int past) {
        
        if(visited[idx] == -1){
            if(past == -1) return;
            else if(past == 2){
                visited[idx] = 3;   // conflict
                return;
            }
        }
        else if(visited[idx] == 2 || visited[idx] == 3){
            return;
        }
        else if(visited[idx] == 0){
            if(past == -1) visited[idx] = -1;
            else if(past == 2) visited[idx] = 2;
        }
        
        for(int i : adj[idx]){
            DFS(adj, i, visited, past);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<int> visited(n, 0);

        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        DFS(adj, k, visited, -1);

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                DFS(adj, i, visited, 2);
            }
        }

        // conflict exists => remove nothing
        for(int i = 0; i < n; i++){
            if(visited[i] == 3){
                for(int j = 0; j < n; j++)
                    ans.push_back(j);
                return ans;
            }
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == 2 || visited[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};