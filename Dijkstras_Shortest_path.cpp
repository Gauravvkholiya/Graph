#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int,int>>> map;
    void edge(int u, int v, int w, bool dir)
    {
        map[u].push_back(make_pair(v,w));
        if (dir == 0)
        {
            map[v].push_back(make_pair(u,w));
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
        cin>>w;
        g.edge(u, v,w, 0);
    }
    return 0;
}