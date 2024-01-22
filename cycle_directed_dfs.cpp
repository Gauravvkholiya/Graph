#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>adj[], int vis[],int pathvis[])
{
    vis[node ] = 1;
    pathvis[node] = 1;
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis ,pathvis)==true){
                return true;
            }
        }
        // the node has to be visited on the same path 

        else if (pathvis[i])
        {
            return true;
        } 
    }
    pathvis[node] = 0;
    return false;
}

bool iscyclic(int node , vector<int>adj[])
{

    // t.c = O(N)+ O(E)
    //S.C = O(2N)
    int vis[node];
    int pathvis[node]={0};
    for(int i =0;i<node;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,pathvis)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    return 0 ;
}