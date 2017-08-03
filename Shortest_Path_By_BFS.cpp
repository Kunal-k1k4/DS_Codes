/* Bfs is used to find shortest path when all the edge weights are same */


// @ -- Kunal Singh (KSR) --




#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>



using namespace std;




typedef long long int lli;
typedef vector<int> vi;
typedef vector<char> vc;
typedef map<int,int> mii;
typedef map<int,char> mic;
typedef map<char,int> mci;
typedef map<char,char> mcc;
typedef set<int> si;
typedef set<char> sc;

bool visited[100000];
long long int c[100000],n,m;
vi nodes[100000];

int BFS(int s)
{

    for(int i=0;i<=m*n;i++)
        {
            c[i]=10000000000;
            visited[i]=false;
        }

    queue<int> Q;
    Q.push(s);

    visited[s]=true;
    c[s]=0;
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        int b=nodes[v].size();

        for(int i=0;i<b;i++)
        {
            if(visited[nodes[v][i]]==false)
            {
                Q.push(nodes[v][i]);
                visited[nodes[v][i]]=true;
            }
            if(c[nodes[v][i]]>(c[v]+1))
                {
                    c[nodes[v][i]]=c[v]+1;
                }
        }
    }

}


int main()
{

    int x,y,s,e;

    cin>>m>>n;
    //m is number of nodes
    //n is number of edges

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        nodes[x].push_back(y);
    }

    cin>>s>>e; //starting position or from where to start and ending position

    BFS(s);

    cout<<c[e]<<endl;
}
