#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int p[1000001];

void sieve()
{
    for(long long int i = 0;i<=1000000;i++)p[i] = 1;
    p[1]=0;
    for(long long int i = 3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(long long int j = i*i;j<=1000000;j+=i)
                p[j] = 0;
        }
    }

}
int segmented_sieve(long long a,long long b)
{
        sieve();
        bool pp[b-a+1];
        memset(pp,1,sizeof(pp));
        for(long long i = 2;i*i<=b;i++)
        {
            for(long long j = a;j<=b;j++)
            {
                if(p[i])
                {
                    if(j == i)
                        continue;
                    if(j % i == 0)
                        pp[j-a] = 0;
                }
            }
        }
        int res = 0;
        for(long long i = a;i<=b;i++)
        {
            if(i==1)
                continue;
                res += pp[i-a];

        }
        return res;
}

int main()
{
    int t;

    cin>>t;

    int a,b;

    while(t--)
    {
        cin>>a>>b;

        cout<<segmented_sieve(a,b)<<endl;
    }
}
