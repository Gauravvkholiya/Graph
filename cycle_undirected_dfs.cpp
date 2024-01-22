#include<bits/stdc++.h>
using namespace std;
bool dfs(int node ,int parent ,int vis[],vector<int>adj[])
{
    vis[node] = 1;
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            if(dfs(i, node,vis,adj)==true)
            return true;
        }
        else if(i != parent)
        {
            return true;
        }
        
    }
    return false;
}

bool iscycle(int node , vector<int>adj[])
{
    // components
    // S.C = O(N)+ O(N)
    //T.c = O(N)+ O(2E) + O(N)
    int vis[node] = {0};
    for(int i =0;i<node;i++)
    {
        if(!vis[i])
        if( dfs(1,-1,vis,adj)==true)
        return true;
    }
    return false;
}
int main()
{
    return 0 ;
}