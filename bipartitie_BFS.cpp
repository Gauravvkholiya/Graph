#include<bits/stdc++.h>
using namespace std;
bool isBipartite(int start , vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(start);
    color[start] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto i: adj[node])
        {
            if(color[i]==-1)
            {color[i] = !color[node];
            q.push(i);
            }
            else if(color[i]==color[node])
            return false;    // if same color of adjacents 
        }
    } 
    return true;
}
bool check(int node, vector<int>adj[])
{

    //different components;
    //T.c = O(2E)+ O(N)
    int color[node];
    for(int i =0;i<node;i++)
    color[i] = -1;
    for(int i =0;i<node;i++)
    {
        if(color[i]==-1)
        {
            if(isBipartite(i,adj,color)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    return 0 ;
}