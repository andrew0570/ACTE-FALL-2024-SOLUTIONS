#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define dbg(x) std::cout<<#x<<" = "<<x<<endl;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define eraseval(vec, val) vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
using ll=long long;
using namespace std;
using graph = std::map<char, std::vector<pair<char,int>>>;
//note that this algorithm runs in O(V+E) for V=# of nodes, and E=# of edges, making this algorthim both linear and pretty fast.

void dfs(char dfstart,graph& g,std::map<char,bool>&visited,stack<char>&topostack) //apply a recursive depth first search to visit every node.
{
    visited[dfstart]=true;
    for(auto &p:g[dfstart]) //connecting node, cost
    {
        char neighbor=p.fi;
        if(!visited[neighbor])//not visited
        {
            dfs(neighbor,g,visited,topostack);

        }
    }
    topostack.push(dfstart); //as we visited every neighbor of any node n, node n gets added to the stack(first in, last out)
    // cout<<"pushing "<<dfstart<<endl; //what we are adding to the stack as we visit all of dfstart's neighbors
}

auto topologicalSort(graph g)
{
    map<char,bool>visited; //keep track of what nodes we have visited
    for(auto pair:g)
    {
        visited[pair.fi]=false; //in the beginning we haven't visited anywhere yet
    }
    stack<char>topostack;
    for(auto&p:g) //apply the dfs for every node in the graph, but this isn't strictly neccesary.
    {
        if(!visited[p.fi])
        {
            dfs(p.fi,g,visited,topostack);
        }
    } //now our topostack is full

    // stack<char>ty=topostack; //print out information
    // cout<<"the topostack.size is "<<topostack.size()<<endl; //the size of the stack
    // while (!topostack.empty()) //print out the stack
    // {
    //     std::cout << topostack.top() << " ";
    //     topostack.pop();
    // }
    // return ty;


    return topostack;


}

int longestPath(graph g,stack<char>topostack,char start,char end)
{
    map<char,int>distance;
    for(auto& pair:g)
    {
        distance[pair.fi]=INT_MIN; //declare all the distances as the minimum because we are trying to maximize the distance
    }
    distance[start]=0;//we start at the start, so the distance to the start is zero
    while (!topostack.empty()) 
    {
        char u = topostack.top();
        topostack.pop(); //remove the first node
        if(u==end){break;} //if the current node is the destination, we have arrived and can break
        for (auto& p : g[u]) //otherwise, just continue, building out the distances
        { 
            char v = p.first;
            int edge_cost = p.second;
            
            if (distance[u] + edge_cost > distance[v]) //if the distance between the current node and its connection is greater than the connecting node we already have
            {
                distance[v] = distance[u] + edge_cost; //we update the distance because we found a new longer distance and we need to maximize the distance
            }
        }
    }

    // if (distance[end] != INT_MIN) //print out the longest distance 
    // {
    //     std::cout << "Longest path from " << start << " to " << end << ": " << distance[end] << "\n";
    // }

    return distance[end];
}



int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    graph g;
    char start,end;
    cin>>start>>end;
    for(int index=0; index<k; index++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        pair<char,int>p;p.fi=b;p.se=c;
        g[a].pb(p);

    }

    // dbg(start);dbg(end); //printing out the graph and the starting and ending nodes.
    // for(const auto &pair:g) //for every node with connections
    // {
    //     for(const auto &p2:pair.se) //print out every connecting node and its cost
    //     {
    //         cout<<pair.fi<<" connects to "<<p2.fi<<" with cost "<<p2.se<<endl;
    //     }
    // }
    // cout<<"------------------------"<<endl;

    stack<char>topostack=topologicalSort(g);
    int cost=longestPath(g,topostack,start,end);
    cout<<cost<<endl; 




}
