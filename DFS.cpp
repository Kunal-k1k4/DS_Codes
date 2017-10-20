#include<iostream>
#include<map>
#include<list>
#include<cstring>
#include<queue>

//DFS

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

    int dfsHelper(T node,map<T,bool> &visited)
    {
        //whenever to come to a node, mark it visited
        visited[node]= true;
        cout<<node<<" ";

        //try to find out a node which is neighbour of current node and not yet visited

        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        dfsHelper(src,visited);
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

    g.dfs("Delhi");

    return 0;
}
