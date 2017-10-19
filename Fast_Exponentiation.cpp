#include<iostream>
#include<cmath>
using namespace std;

//Fast Exponentiation O(log n)

int power(int a,int b)
{
    //base case
    if(b==0)
        return 1;

    //recursive case
    int smallerAns = power(a,b/2);
    smallerAns*=smallerAns;

    if(b&1)
        smallerAns*=a;

    return smallerAns;
}


int main()
{
    int a,b;
    cin>>a>>b;

    cout<<power(a,b);
}
