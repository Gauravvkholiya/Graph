#include<bits/stdc++.h>
using namespace std;
bool dfs(int node ,int col , vector<int>adj[],int color[])
{
    color[node] = col;
    for(auto i : adj[node])
    {
        if(color[i]==-1)
        dfs(i,!col,adj,color);
        else if(color[i]== col)
        {
            return false;
        }
    }
    return true;
}
bool check(int node, vector<int>adj[])
{

    //different components;
    //T.c = O(2E)+ O(N)
    //S.C = O(3N)
    int color[node];
    for(int i =0;i<node;i++)
    color[i] = -1;
    for(int i =0;i<node;i++)
    {
        if(color[i]==-1)
        {
            if(dfs(i,0 ,adj,color)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    return 0 ;
}