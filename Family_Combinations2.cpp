#pragma GCC optimize("Ofast","unroll-loops")
#include <bits\stdc++.h>
#define dbg(x) std::cout << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll=long long;

/*

ABCCDEEAABCDE
2
AB
CD

*/



int main() //brute force solution
{
    freopen("input2.in", "r", stdin);
    auto start = std::chrono::high_resolution_clock::now();

    string input;
    cin>>input;
    int n;
    cin>>n;

    std::unordered_set<string> forbid;  
    for (int index = 0; index < n; ++index) 
    {
        string str;
        cin>>str;
        forbid.insert(str);
        reverse(all(str));
        forbid.insert(str); 
    } //we add the reversed (given) strings to the list of forbidden strings
    //we need to check for both ab and ba because in both cases, a and b are next to each other

    ll ans=0;
    int flag=0;

    // Sorting makes sure that only unique permutations are generated, saving a small amount of compute time
    sort(all(input));

    do //for every permutation, check if there is an invalid substring
    {
        //cout<<"permutation"<<" "<<input<<endl;

        flag=0;
        for (const auto& k : forbid) //loop through the set to check whether each 
        {
            if (input.find(k)!=string::npos) //if we find a fprbidden string
            {
                flag=1;
                break; //just break because we know that, at this point, it is forbidden
            }
        }
        if(flag==0){ans++;} //we didn't find a forbidden substring so we find a valid permutation

    }while(next_permutation(all(input)));




    //the above algorithm is very inefficient, runnning in something like O(n!*m).
    //can you apply a mathematical principle to make it more efficient? (Something relating to multiset counting?)


    //dbg(ans);
    cout<<ans<<endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;
}
