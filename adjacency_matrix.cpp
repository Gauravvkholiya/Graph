#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int matrix[n+1][m+1];
    for(int i =0;i<m;i++)
    {   
        int u,v;
        cin>>u>>v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    return 0 ;
}