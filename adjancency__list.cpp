#include<bits/stdc++.h>
using namespace std;
int main()
{
    //T.C -> O(2E) in undirected and O(E) in directed is the space complexity 
    int n ,m;    //n ->nodes && m ->edges 
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);  //in the case of directed it will not be there

    }
    return 0 ;
}