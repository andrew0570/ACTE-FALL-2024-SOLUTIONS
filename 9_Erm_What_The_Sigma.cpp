#include <bits/stdc++.h>

#define dbg(x) std::cout<<#x<<" = "<<x<<endl;

using namespace std;

int main()
{
    int n,sum,size;
    cin>>n;
    cin>>size;
    vector<int>s(size);
    for(auto &c:s) //read in all the numbers we will need to cahck for divisibility
    {
        cin>>c;
    }

    //for(const auto &c:s){cout<<c<<" ";}cout<<endl; //this would output the above vector

    for(int index=1; index<=n; ++index) //for every number between 1,n inclusive
    {
        for(auto const& c:s) //check if it is divisible by atleast one number in the vector
        {
            // cout<<"index is "<<index<<" and ";
            // dbg(c);

            if(index%c==0) //if it is divisible, then we add it to the running sum
            {
                sum+=index;
                //cout<<index<<endl;
                break;
            }
        }
    } //this process in the worst case, runs in O(n^2). Can you find a more efficient method?
    cout<<sum<<endl;

}
