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
        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

            cout<<node<<" ";

            //for the neighbours of the current node, find out the nodes which are not visited

            for(auto neighbour : adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
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
