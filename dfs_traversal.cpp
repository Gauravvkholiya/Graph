#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> map;
    void edge(int u, int v, bool dir)
    {
        map[u].push_back(v);
        if (dir == 0)
        {
            map[v].push_back(u);
        }
    }
    void dfs(unordered_map<int, bool> &vis, int node, vector<int> &ans)
    {
        ans.push_back(node);
        vis[node]=1;
        for(auto i: map[node])
        {
            if(!vis[i])
            {
                dfs(vis,node,ans);
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
        int u, v;
        cin >> u;
        cin >> v;
        g.edge(u, v, 0);
    }
    vector<int> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            g.dfs(visited, i, ans);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
    return 0;
}