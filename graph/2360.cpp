#include<bits/stdc++.h>
using namespace std;

// we can use dfs to find the longest cycle in the graph. we can keep track of the count of nodes in the current path and if we find a node that is already in the current path, then we can update the result with the maximum of the current result and the count of nodes in the current path minus the count of nodes in the cycle plus one. we can also keep track of the visited nodes to avoid cycles.


class Solution {
public:
    int result=-1;
    void solve(int u,vector<int>& edges,vector<bool> &visited, vector<int> &cnt,vector<bool> &inRec){
        if(u!=-1){
            visited[u]=true;
            inRec[u]=true;
            int v=edges[u];
            if(v!=-1 && !visited[v]){
                cnt[v]=cnt[u]+1;
                solve(v,edges,visited,cnt,inRec);
            }
            else if(v!=-1 && inRec[v]){
                result=max(result,cnt[u]-cnt[v]+1);
            }
            inRec[u]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
       int n=edges.size();
       vector<bool> visited(n,false);
       vector<int> cnt(n,1);
       vector<bool> inRec(n,false);
       for(int i=0;i<n;i++){
         if(!visited[i]){
            solve(i,edges,visited,cnt,inRec);
         }
       }
       return result;
    }
};