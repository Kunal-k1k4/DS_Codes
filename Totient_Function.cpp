#include <iostream>
using namespace std;

int toi(int n)
{

    int result=n,temp=n;
    for(int i=2;i*i<=n;i++)
    {
        if(temp%i==0)
        {
            result-=(result/i);
            while(temp%i==0)
            {
                temp/=i;
            }
        }
    }

    if(temp!=1)
    {
        result-=(result/temp);
    }

    return result;
}

int main() {

    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        cout<<toi(n)<<endl;
    }
}
