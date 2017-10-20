#include<iostream>
#include<cmath>
#include<list>
using namespace std;

class Graph
{
    int V;
    //Array of Linked List of size v

    list<int> *adjList;

    public:

    Graph(int v)
    {
        V=v;
        adjList = new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_back(v);

        if(bidir)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int node:adjList[i])
            {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    G.addEdge(1,3);
    G.addEdge(3,2);

    G.printAdjList();

    return 0;
}
