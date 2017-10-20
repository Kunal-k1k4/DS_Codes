#include<iostream>
#include<map>
#include<list>
#include<cstring>
#include<queue>

//BFS

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

    void bfs(T src)
    {

        cout<<"BFS Traversal :"<<endl;
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;

        for(auto i : adjList)
            dist[i.first]=INT_MAX;

        q.push(src);
        dist[src]=0;
        parent[src]=src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

            cout<<node<<" ";

            //for the neighbours of the current node, find out the nodes which are not visited

            for(auto neighbour : adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        cout<<endl;

        cout<<"Shortest Path Using BFS :"<<endl;

        //print the distance to all the nodes

        for(auto i : adjList)
        {
            T node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }

};

int main()
{
    Graph<string> g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Siachen");
    g.addEdge("Delhi","Bangalore");
    g.addEdge("Delhi","Agra");
    g.addEdge("Amritsar","Siachen");

    g.bfs("Delhi");

    return 0;
}
