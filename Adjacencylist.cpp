#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
unordered_map<int,list<int>>map;
void edge(int u ,int v,bool dir)
{
    map[u].push_back(v);
    if(dir== 0)
    {
        map[v].push_back(u);
    }
}
void printlist()
{
    for(auto i :map)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
}
};
int main()
{
    Graph g;
    int edges,nodes;
    cout<<"enter the no of edges ";
    cin>>edges;
    cout<<"enter the no of nodes ";
    cin>>nodes;
    for(int i =0;i<edges;i++){
        int u,v;
        cin>>u ;
        cin>>v;
        g.edge(u,v,0);
    }
    g.printlist();
return 0;
}