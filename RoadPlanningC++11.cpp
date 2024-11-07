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

//add stipulation in the problem description that there will only be at most, 26 possible cities.


using graph = std::map<char, std::vector<pair<char,float>>>;

float distance(float x1,float y1,float x2,float y2) //distance formula for 2 euclidean (x,y) points
{
    float dx=x2-x1;
    float dy=y2-y1;
    float dist=sqrt((dx*dx)+(dy*dy));
    return dist;
    //float dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}


float primsMST(graph g,char start) //implementation of Prim's algorithm for constructing a minimum spanning tree.
{
    //need a priority queue that picks the smallest edge from amongst all the edges of 'A' connecting to every other node
    priority_queue<pair<float, pair<char, char>>, vector<pair<float, pair<char, char>>>, greater<pair<float, pair<char, char>>>> pq;
    map<char,vector<char>>MST;
    map<char,bool>inMST;
    for(auto const pair:g)
    {
        inMST[pair.fi]=false;
    }
    inMST[start]=true;
    auto v=g[start]; //where v is the vector
    for(const auto& k: v) //vector<pair<char,float>>
    {
        pq.push({k.se,{start,k.fi}}); //<cost<parent,child>
    }
    while(!pq.empty())
    {
        auto topel=pq.top();
        pq.pop();
        if(!inMST[topel.se.se])
        {
            //MST[topel.se.se]=topel.fi; (ignore)
            MST[topel.se.fi].pb(topel.se.se);
            inMST[topel.se.se]=true;
            auto vv=g[topel.se.se];
            for(auto const &k:vv)
            {
                pq.push({k.se,{topel.se.se,k.fi}});
            }
        }
    }
    float cost;
    for(const auto& pair:MST)
    {
        for(const auto& kk:pair.se)
        {
            cout<<pair.fi<<" -> "<<kk<<endl;
        }
    }

    for (const auto& p1 : MST) 
    {//[parent,children]
        for (const char child : p1.se) 
        {
            // Find the cost of the edge from parent to child
            auto it = find_if(all(g[p1.fi]), [child](const pair<char, float>& edge) {return edge.first == child;}); // Match child node
            if (it != g[p1.fi].end())
            {
                cost += it->second; // Add the cost of the edge (note: -> is the de-referencer )
            }
        }
    }

    // dbg(cost);
    return cost;
}




int main()
{
    
    freopen("input1.in","r",stdin);
    auto start = std::chrono::high_resolution_clock::now();
    int budget;
    cin>>budget;
    int k;
    cin>>k;
    map<char,pair<int,int>>coords;
    for(int index=0; index<k; index++) //read in the city and its x,y coordinates.
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        pair<int,int>p;
        p.fi=x;p.se=y;
        coords[c]=p;

    }
    graph g; //using graph = std::map<char, std::vector<std::pair<char, float>>>
    
    // for (const auto &[key, value]: coords) 
    // {
    //     cout<<key<<" "<<value.fi<<"  "<<value.second<<endl;
    // }

    for(const auto &pair1:coords)
    {
        vector<pair<char,float>>v;
        for(const auto &pair2:coords)
        {
            if(pair1.fi!=pair2.fi)
            {
                pair<char,float>p;
                p.fi=pair2.fi;
                p.se=distance(float(pair1.se.fi),float(pair1.se.se),float(pair2.se.fi),float(pair2.se.se));//float x1,float x2,float y1,float y2
                v.pb(p); 
            }
        }
        g[pair1.fi]=v;
    }
    cout<<endl<<"<>"<<endl;
    for(const auto &pair1:g)
    {
        cout<<pair1.fi<<" connects to\n";
        for(const auto &k:pair1.se)
        {
            cout<<k.fi<<" with cost "<<k.se<<endl;
        }
        cout<<"---------------------"<<endl;
    }
    float cost=primsMST(g,g.begin()->first);
    cout<<"The cost is "<<cost<<endl;
    if(cost<budget)
    {
        cout<<"True"<<endl;
    }
    else{cout<<"false"<<endl;}



    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;

    return 0;
    

}
