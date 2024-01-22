 #include<bits/stdc++.h>
 using namespace std;
 bool detect(int src , vector<int>adj[], int vis[]  )
 {
    vis[src] =1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i : adj[node])
        {
            if(!vis[node])
            {
                vis[node] = 1;
                q.push({i,node});
            }
            else if(parent != i )
            {
                 return true;
            }
        }
    }
    return false;
 }
 bool iscycle(int n , vector<int>adj[])
 {
    //T.C == O(2E)+O(N)
    //S.C = O(3N)
    //if the graph is broken in components 
    int vis[n] = {0};
    //0-based
     for(int i =0;i<n;i++)
     {
        if(!vis[i])
        {
            if(detect(i,adj,vis))
            return true;
        }
     }
     return false;
 }
 
 int main()
 {
     return 0 ;
 }