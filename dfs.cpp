#include<bits/stdc++.h>
using namespace std;
void dfs(int node , vector<int>adj[],int vis[], vector<int>&ans)
{
    //0-based
    //T.c -> O(N) +O(2E)
    //S.c ->O(N) +O(N)+O(N)
    vis[node] =1;
    ans.push_back(node);
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,ans);
        }
    }

}


int main()
{
    int n ,m;  
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int vis[n] = {0};
    int starting_node = 0;
    vector<int>ans;
    dfs(starting_node,adj,vis,ans);
    return 0 ;
}