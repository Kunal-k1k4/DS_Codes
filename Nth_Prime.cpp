#include<iostream>
#include<vector>
#include<set>
using namespace std;


//FIND Nth PRIME NUMBER

vector<int> prime_vector;
set<int> notprime;
bool v[100000005];
int steve()
{
    for(long long int i=2;i<=100000005;i+=2)
    {
        v[i]=true;
    }

    prime_vector.push_back(2);

    for(long long int i = 3; i < 100000005;i+=2)
    {
        if(!v[i])
        {
            prime_vector.push_back(i);

            for(long long int j = i;(j*i)< 100000005;j+=2)
            {
                if(!v[j*i])
                    v[j*i]=true;
            }
        }
    }
}
int main() {
    steve();

    int n;

    cin>>n;

    cout<<prime_vector[n-1]<<endl;
	return 0;
}
