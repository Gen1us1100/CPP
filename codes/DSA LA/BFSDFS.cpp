/*Represent a graph using adjacency matrix/list in DFS adjacence list as BFS
Use college landmarks as nodes
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>>& graph , int start,vector<int>& vis)
{
    vis[start]=1;
    cout<<start<<" ";
    
    for(auto child: graph[start])
    {
        if(!vis[child])
        {
            dfs(graph,child,vis);
            
        }
    }
}

void bfs(vector<vector<int>>& graph , int start)
{
    vector<int>vis(graph.size(),0);
    queue<int>q;
    
    q.push(start);
    
    vis[start]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        
    for(auto child: graph[curr])
    {
        if(!vis[child])
        {
            q.push(child);
            vis[child]=1;
            
        }
    }
    }
}

void adjmtx(vector<vector<int>>& graph)
{
    
    vector<vector<int>>am(graph.size(),vector<int>(graph.size(),0));
    for(int i=0;i<graph.size();i++)
    {
        for(int j : graph[i])
        {
            am[i][j] = 1;
            am[j][i] = 1;
        }
    }
    
    cout<<"\nAdjacency matrix : \n";
    
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            cout<<am[i][j]<<" ";
        }
        cout<<endl;
    }
}

void adjlst(vector<vector<int>>& graph)
{
    cout<<"\n adjacency list \n";
    for (int i = 0; i<graph.size();i++)
    {
    cout<<i<<" -- > ";
    
        for(int j : graph[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int V;
    cout<<"\nNo of vertices : ";
    cin>>V;
    vector<vector<int>>graph;
    
    for(int i=0;i<V;i++)
    {
        vector<int>temp;
        graph.push_back(temp);
    }
    
    cout<<"\nNo of Edges : ";
    int E;
    cin>>E;
    cout<<"\nEnter nodes which are connected : (format : a b ) : \n";
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    adjmtx(graph);
    cout<<endl;
    adjlst(graph);
    cout<<endl;    
    vector<int>vis(V,0);
    cout<<"\nDFS is : ";
    dfs(graph,1,vis);
    
    cout<<"\nBFS is : ";
    bfs(graph,1);
    return 0;
}