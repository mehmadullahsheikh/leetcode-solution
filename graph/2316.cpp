#include<bits/stdc++.h>
using namespace std;

// count the nodes in each connected component and then calculate the number of pairs using that multiply the last count with the current count and add it to the answer and then update the last count by adding the current count to it. we can use dfs to count the nodes in each connected component.

class Solution {
public:
    int solve(int u, unordered_map<int,vector<int>> &adj, vector<bool> &visited){
        int cnt=1;
        if(visited[u]) return 0;
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
               cnt+=solve(v,adj,visited);    
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        long long ans=0;
        long long last=-1;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int val=solve(i,adj,visited);
                if(last==-1){
                    last=val;
                }else{
                    ans+=(last*val);
                    last+=val;
                }
            }
        }
        return ans;
    }
};