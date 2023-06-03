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
    void bfs(unordered_map<int, bool> &vis, int node, vector<int> &ans,int t)
    {
        unordered_map<int,int>parent;
        queue<int> q;
        parent[node] = -1;
        q.push(node);
        vis[node] = 1;
        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            for (auto i : map[frontnode])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = 1;
                    parent[i] = frontnode;
                }
            }
        }

        int currentnode = t;
        ans.push_back(currentnode);
        while(currentnode!= node)
        {
            currentnode = parent[currentnode];
            ans.push_back(currentnode);
        }
    }
    // void printadj()
    // {
    //     for(auto i :map)
    //     {
    //         cout<<i.first<<"->";
    //         for(auto j:i.second)
    //         {
    //             cout<<j<<",";
    //         }
    //         cout<<endl;
    //     }
    // }
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
    int s,t;
    cout<<"enter the source node";
    cin>>s;
    cout<<"enter the destination node";
    cin>>t;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            g.bfs(visited, s, ans,t);
        }
    }
    reverse(ans.begin(),ans.end());
    // g.printadj();
    cout<<"shortest path is :"<<endl;
    for(int i =0;i<ans.size();i++)
    {
        cout<<ans[i]<<",";
    }
}