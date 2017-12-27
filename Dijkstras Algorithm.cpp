#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{

    int t;

    cin>>t;

    while(t--)
    {
        int n,e,w,x,y,s;

        cin>>n>>e;

        vector<pair<int,int> > q[100001];

        pair<int,int> p,p1;
        pair<int,pair<int,int> > pp;
        priority_queue<pair<int,int> > pq;

        for(int i=1;i<=e;i++)
        {
            cin>>x>>y>>w;

            q[x].push_back(make_pair(y,w));
            q[y].push_back(make_pair(x,w));
        }

        cin>>s;


        int dist[100001];

        for(int i=0;i<100001;i++)
            dist[i]=100000000;

        dist[s]=0;

        p1=make_pair(dist[s],s);

        pq.push(p1);

        while(!pq.empty())
        {
            p1 = pq.top();
            pq.pop();

            int node = p1.second;
            int w = -1*(p1.first);
            int size = q[node].size();
            for(int i=0;i<size;i++)
            {
                p1 = q[node][i];
                int weight = p1.second;
                if(dist[p1.first] > w+weight)
                {
                    dist[p1.first]=w+weight;
                    p=make_pair(-1*dist[p1.first],p1.first);
                    pq.push(p);
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(i!=s)
            {
                if(dist[i]!=100000000)
                    cout<<dist[i]<<" ";
                else
                    cout<<"-1"<<" ";
            }
        }
        cout<<endl;



    }

}
