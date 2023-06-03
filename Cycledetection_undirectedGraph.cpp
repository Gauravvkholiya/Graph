#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
unordered_map<int,list<int>>map;
void edge(int u ,int v,bool dir)
{
    map[u].push_back(v);
    if(dir==0)
    {
        map[v].push_back(u);
    }
}
bool bfs(unordered_map<int,bool>&vis,int node)
{
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(node);
    parent[node]=-1;
    vis[node]= 1;
    while(!q.empty())
    {
        int frontnode= q.front();
        q.pop();
        for(auto i :map[frontnode])
        {
            if(vis[i]==true&&i!=parent[frontnode])
            {
                return true;
            }
            else if(!vis[i]){
                q.push(i);
                vis[i] = true;
                parent[i] = frontnode;
            }
        }
    }
    return false;
}
};
int main()
{
    Graph g;
    int edges,nodes;
    cout<<"enter the no of edges";
    cin>>edges;
    cout<<"enter the no of nodes";
    cin>>nodes;
    for(int i = 0;i<edges;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        g.edge(u,v,0);
    }
    unordered_map<int,bool>visited;
    bool ans;
    for(int i =0;i<nodes;i++)
    {
        if(!visited[i])
        {
            ans = g.bfs(visited,i);
        }
    }
    if(ans==1)
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
return 0;
}