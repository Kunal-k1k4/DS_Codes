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
    void addEdge(T u,T v,bool bidir=false)
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

    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering)
    {
        visited[node]=true;

        //will call dfs on the unvisited neighbours of the current node
        for(T neighbour : adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited,ordering);
            }
        }
        //Add 1 line for TS
        //At this point all the children of current node have been visited
        //So we can add current node to the list

        ordering.push_front(node);
    }

    void dfsTopologicalSort()
    {
        map<T,bool> visited;
        list<T> ordering;

        for(auto i: adjList)
        {
            T node = i.first;

            if(!visited[node])
            {
                dfsHelper(node,visited,ordering);
            }
        }

        //Print all the elements in ordering

        for(T element:ordering)
            cout<<element<<" ";
    }



};

int main()
{
    Graph<string> g;
    g.addEdge("Delhi","Amritsar");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Siachen");
    g.addEdge("Delhi","Bangalore");
    g.addEdge("Delhi","Agra");
    g.addEdge("Amritsar","Siachen");


    g.dfsTopologicalSort();
    return 0;
}
