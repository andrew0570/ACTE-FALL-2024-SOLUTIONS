/*
    Uses topological sorting to create an ordered list of both the rows and the columns separately. 
    
      1) Create graph from input, connecting all items (1-N) to all items that must be below that item
      2) Create an array tracking the number of items that must be above each item
      3) Use topological sort helper method to create row order and column order separately
      4) Output the matrix by iterating through the rows and columns, outputting the item number if it is placed in that row and column or else 0

    Topological Sort:
      1)
*/

#include <bits/stdc++.h>

using namespace std;

void topoSort(vector<vector<int>> &graph, vector<int> &deg, vector<int> &order, int n){
    int curr;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++) if(deg[i]==0) pq.push(i);

    while(!pq.empty()){
        curr=pq.top(); pq.pop();
        n--;
        order.push_back(curr);
        for(int i:graph[curr]) if(--deg[i]==0) pq.push(i);
    }
    if(n!=0) order.clear();
}

int main(){

    // GETTING USER INPUT AND SORTING
    int n, k, a, b;
    cin>>n;

    vector<vector<int>> graph(n+1);
    vector<int> inDeg(n+1);
    vector<int> rows;
    cin>>k;
    while(k-->0){
        cin>>a; cin>>b;
        graph[a].push_back(b);
        inDeg[b]++;
    }
    topoSort(graph,inDeg,rows,n); // Sort vector 'rows' in topological order of items

    graph=vector<vector<int>>(n+1);
    inDeg=vector<int>(n+1);
    vector<int> cols;
    cin>>k;
    while(k-->0){
        cin>>a; cin>>b;
        graph[a].push_back(b);
        inDeg[b]++;
    }
    topoSort(graph,inDeg,cols,n); // Sort vector 'cols' in topological order of items

    if(rows.empty()||cols.empty()){cout<<"-1"<<endl;return 0;} // if rows or cols is empty, it is impossible to create a matrix under the conditions

    // OUTPUTTING MATRIX USING 'rows' AND 'cols'
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rows[i]==cols[j]) cout<<rows[i]<<' '; // if row and col matches, fill matrix position, else empty '0'
            else cout<<"0 ";
        }
        cout<<endl;
    }
    
    return 0;
}
