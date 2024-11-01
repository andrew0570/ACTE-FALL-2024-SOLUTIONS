/*
    Uses Djikstra's algorithm to compute path of greatest probability
    
      1) create graph, representing all the cities the current city connects to and their respective probabilities
      2) create list of maximum probabilities to reach city at that index; initialize to -1 for if it can't be reached
      3) create priority queue to order paths based on maximum probability
      4) traverse through graph, starting at src; at each city, update max probability list or stop traversing depending on current safety probability and add all adjacent cities to queue
      5) output maximum probability to reach dst
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<double,char> node;

int main(){
    // VARIABLES
    char src, dst;
    int n;
    map<char,vector<node>> paths; // maps char(city) to paths with float "cost"
    vector<double> maxSafety(26,-1); // vector holds the minimum distances from src to index city (A=0, B=1, ...)

    // GETTING INPUT & BUILDING GRAPH
    cin>>src>>dst;
    cin>>n;
    while(n-- > 0){
        char a, b; double c;
        cin>>a>>b; cin>>c;
        // add both for bidirectional path
        paths[a].push_back({c,b}); 
        paths[b].push_back({c,a});
    }

    // DJIKSTRA's ALGORITHM
    priority_queue<node, vector<node>, less<node>> pq;
    pq.push({1,src}); // start with 100% at src city

    while(!pq.empty()){
        auto[curr,city] = pq.top();
        pq.pop();
        if(curr<=maxSafety[city-65]) continue; // remove city if it has already been visited with higher probability
        
        maxSafety[city-65]=curr;
        for(node i:paths[city]){ // iterate through all adjacent cities
            if(i.first*curr>maxSafety[i.second-65]) pq.push({i.first*curr,i.second});
        }
    }

    // RESULT
    cout << maxSafety[dst-65] << endl;

    return 0;
}
