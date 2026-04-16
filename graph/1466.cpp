#include<bits/stdtr1c++.h>
using namespace std;

///  make graph connection bi-directional and assign cost 1 for original direction and 0 for reverse direction. Then do dfs and count the cost of edges which are in original direction.

class Solution {
public:
    int cnt = 0;
    int solve(int u, vector<bool> &visited, unordered_map<int, vector<pair<int,int>>> &adj) {
        visited[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first;
            int cost = p.second; 

            if (!visited[v]) {
                cnt += cost;
                solve(v, visited, adj);
            }
        }
        return 0;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto con : connections) {
            int a = con[0];
            int b = con[1];

            adj[a].push_back({b, 1}); 
            adj[b].push_back({a, 0});
        }

        vector<bool> visited(n, false);
        solve(0, visited, adj);

        return cnt;
    }
};

