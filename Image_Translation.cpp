#pragma GCC optimize("Ofast","unroll-loops") //for gcc compilers
#include <bits\stdc++.h>
#define dbg(x) std::cout<<#x<<" = "<<x<<endl;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define eraseval(vec, val) vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
using ll=long long;
using namespace std;




int main()
{
    freopen("input2.in","r",stdin);
    freopen("output1.out","w",stdout);
    int k,rows,cols; 
    cin>>k; //which translation
    cin>>rows; //num columns
    cin>>cols; //num rows

    // dbg(rows);
    // dbg(cols);

    std::vector<std::vector<char>> array(rows, std::vector<char>(cols)); //since we can't make a dynamic array, we have to use a 2 dimensional vector


    cin.ignore();
    for(int index=0; index<rows; index++) //rows
    {
        string inp;
        getline(cin,inp); 
        for(int i=0; i<inp.size(); i++)//columns
        {
            array[index][i]=inp.at(i);
            //dbg(array[index][i]);
        }
    }


    // for(int index=0; index<rows; index++) //this loop prints out the image we just read in
    // {
    //     for(int i=0; i<cols; i++)
    //     {
    //         cout<<array[index][i];
    //     }
    //     cout<<endl;
    // }


    if(k==1) //rotate 90 deg right
    {
        std::vector<std::vector<char>> transform(cols, std::vector<char>(rows)); //transformed array
        for (int i=0; i<rows; i++) 
        {
            for (int j=0; j<cols; j++) 
            {
        
                transform[j][rows-1-i]=array[i][j];
            }
        }

        for(int index=0; index<cols; index++) //output the transformed array
        {
            for(int i=0; i<rows; i++)
            {
                cout<<transform[index][i];
            }
            cout<<endl;
        }



    }
    else if(k==2) //rotate 90 degrees left
    {
        std::vector<std::vector<char>> transform(cols, std::vector<char>(rows)); //transformed array

        for (int i=0; i<rows; i++) 
        {
            for (int j=0; j<cols; j++) 
            {
                transform[cols-1-j][i]=array[i][j];
            }
        }


        for (int i=0; i<cols; i++)  //output the transformed array
        {
            for (int j=0;j<rows;j++) 
            {
                cout<<transform[i][j];
            }
            cout<<endl;
        }
    }
    else if(k==3) //rotate 180 degrees right (note that 180 degrees right is the same thing as 180 degrees left
                 //so we can use the same if statement for both k=3 and k=4
    {
        std::vector<std::vector<char>> transform(rows, std::vector<char>(cols)); //transformed array

        for (int i=0; i<rows; i++) 
        {
            for (int j=0; j<cols; j++) 
            {
                // Move (i, j) to (rows - 1 - i, cols - 1 - j)
                transform[rows - 1 - i][cols - 1 - j]=array[i][j];
            }
        }

        for (int i=0; i < rows; i++) //output the transformed array
        {
            for (int j=0; j < cols; j++) 
            {
                cout << transform[i][j];
            }
            cout << endl;
        }
    }
    else if(k==4)
    {
        // The dimensions remain the same for a 180-degree rotation
        std::vector<std::vector<char>> transform(rows, std::vector<char>(cols));

        for (int i=0; i < rows; i++) 
        {
            for (int j=0; j < cols; j++) 
            {
                // Move (i, j) to (rows - 1 - i, cols - 1 - j)
                transform[rows - 1 - i][cols - 1 - j]=array[i][j];
            }
        }

        for (int i=0; i < rows; i++) //output transformed array
        {
            for (int j=0; j < cols; j++) 
            {
                cout << transform[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}