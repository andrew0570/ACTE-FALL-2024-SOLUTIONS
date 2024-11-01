//kiddie train
#include <iostream>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
  int N,K; //number of kids and weight capacity
  cin>>N>>K;
  vector<int>weights; //make a vector of weights
  for(int i=0;i<N;i++)
  {
    int num;
    cin>>num;
    weights.push_back(num); //adds each child's weight to vector
  }
  sort(weights.begin(),weights.end()); //sorts vector from least to greatest
  int i=0; //iterator starting from the lightest child
  int j=N-1; //iterator starting from heaviest child
  int numcompartments=0; //keeps running total of the number of comapartments
  while(i<=j) 
  {
    if(weights[i]+weights[j]<=K) //checks if child can be seated with another child
    {
        i++; //pointer moves up
    }
    j--; //pointer moves down
    numcompartments++; //number of compartments increses
  }
  cout<<numcompartments; //prints number of compartments needed
}
