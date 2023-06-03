#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
unordered_map<int,list<pair<int,int>>>map;
void edge(int u ,int v,int w,bool dir)
{
    map[u].push_back(make_pair(v,w));
    if(dir==0)
    {
        map[v].push_back(make_pair(u, w));
    }
}
void dijkstraspath(int source,set<pair<int,int>>&set,vector<int>&distance)
{
    distance[source] = 0;
    set.insert(make_pair(0,source));
    while(!set.empty())
    {
        auto top = *(set.begin());
        int topnode = top.second;
        int topdistance  = top.first;
        set.erase(top);
        for(auto i : map[topnode])
        {
            if(topdistance + i.second< distance[i.first])
            {
                auto record = set.find(make_pair(distance[i.first],i.first));

            
            if(record != set.end())
            {
                set.erase(record);
            }
            distance[i.first] = topdistance + i.second;
            set.insert(make_pair(distance[i.first],i.first));
            }
        }

    }
}
};
int main()
{
    Graph g;
    int edges,nodes;
    cout<<"enter the number of edges";
    cin>>edges;
    cout<<"enter the number of nodes";
    cin>>nodes;
    for(int i =0;i<edges;i++)
    {
        int u ,v ,w;
        cin>>u;
        cin>>v;
        cin>>w;
        g.edge(u,v,w,0);
    }
    vector<int>distance(nodes);
    for (int i = 0; i < nodes; i++)
    {
        distance[i] = INT_MAX;
    }   
    int source;
    cout<<"enter the source node";
    cin>>source;
    set<pair<int,int>>set;
    g.dijkstraspath(source,set,distance);
    
    for(int i =0;i<nodes;i++)
    {
        
    }

return 0;
}