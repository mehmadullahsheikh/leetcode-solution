#include<bits/stdtr1c++.h>
using namespace std;
class Solution {
public:
    int solve(int u,    unordered_map<int,vector<pair<int,int>>> &adj,int n,vector<bool> &visited){
        if(visited[u]) return INT_MAX;
        int total=INT_MAX;
        visited[u]=true;
         for(auto &v : adj[u]){
            int b = v.first;
            int dis = v.second;
            total = min(total, dis);

            if(!visited[b]){
                int val = solve(b, adj, n, visited);
                total = min(total, val);
            }
        }
        return total;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &road:roads){
            int a=road[0];
            int b=road[1];
            int dis=road[2];
            adj[a].push_back({b,dis});
            adj[b].push_back({a,dis});
        }
        vector<bool> visited(n+1,false);
        return solve(1,adj,n,visited);
    }
};