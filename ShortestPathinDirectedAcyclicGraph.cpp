#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int,int>>> map;
    void edge(int u, int v,int w, bool dir)
    {
        map[u].push_back(make_pair(v,w));
        if (dir == 0)
        {
            map[v].push_back(make_pair(u,w));
        }
    }
    void dfs(unordered_map<int,bool>&vis, stack<int>&s,int node)
    {
        vis[node] = true;
        for(auto i :map[node])
        {
            if(!vis[i.first])
            {
                dfs(vis,s,i.first);
            }
        }
    s.push(node);
    }
    void shortestpath(int src,vector<int>&dist,stack<int>&s)
    {
        dist[src] = 0 ;
        s.pop();
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            if(dist[top]!=INT_MAX)
            {
                for(auto i: map[top])
                {
                    if(dist[top]+i.second<dist[i.first])
                    {
                        dist[i.first] = dist[top]+i.second;
                    }
                }
            }
        } 
    }
};


int main()
{
    Graph g;
    int edges, nodes;
    cout << "enter the no of edges";
    cin >> edges;
    cout << "enter the no of nodes ";
    cin >> nodes;
    for (int i = 0; i < edges; i++)
    {
        int u, v,w;
        cin >> u;
        cin >> v;
        cin >> w;
        g.edge(u, v,w, 0);
    }
    vector<int> ans;
    unordered_map<int, bool> visited;
    stack<int>s;
    vector<int>dist(nodes);
    for(int i =0;i<nodes;i++)
    {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            g.dfs(visited ,s ,i);
        }
    }
    int src;
    cout<<"enter the source node:"<<endl;
    cin>>src;

    g.shortestpath(src,dist,s);
    cout<<"the distance array will be :->"<<endl;
    for(int i =0;i<dist.size();i++)
    {
        cout<<dist[i]<<endl;
    }
    return 0;
}