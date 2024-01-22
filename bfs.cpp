#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(int n , vector<int>adj[])
{
    //0-based 

    //T.C -> O(N)+ O(2E)  //queue+ all nodes 
    //S.C -> O(3N)
    int vis[n] = {0};
    queue<int>q;
    q.push(0); // push the starting node 
    vis[0] =1; // mark the starting node as 1
    vector<int>bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto i : adj[node] )
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i] =1;
            }
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
    bfs(n,adj);
    return 0 ;
}