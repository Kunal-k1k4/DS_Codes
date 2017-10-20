#include<iostream>
#include<map>
#include<list>
#include<cstring>
#include<queue>

//DFS Topological Sort

using namespace std;

template<class T>

class Graph
{
    map<T,list<T> > adjList;

    public:

    Graph()
    {

    }
    //Assuming Bidirectional Graph
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);

        if(bidir)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        //Iterate over maps

        for(auto row : adjList)
        {
            T key = row.first;
            cout<<key<<"->";

            for(T element : row.second )
            {
                cout<<element<<" ";
            }
            cout<<endl;
        }
    }

    bool isCyclicBFS(T src)
    {
        map<T,bool> visited;
        map<T,int> parent;

        queue<T> q;

        q.push(src);
        visited[src]=true;
        parent[src]=src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

            for(T neighbour : adjList[node])
            {
                if(visited[neighbour]==true && parent[node]!=neighbour)
                {
                    return true;
                }
                else
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]=true;
                        parent[neighbour]=node;
                        q.push(neighbour);
                    }
                }
            }
        }

        return false;
    }


};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    //g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);

    if(g.isCyclicBFS(1))
        cout<<"Cyclic Graph"<<endl;
    else
        cout<<"Not a Cyclic Graph"<<endl;

    return 0;
}
