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

    bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack)
    {
        //processing the current node - visited
        visited[node]=true;
        inStack[node]=true;

        for(T neighbour : adjList[node])
        {
            if(!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack) || inStack[neighbour])
            {
                return true;
            }
        }
        //Going to pop out the node , inStack = false
        inStack[node]=false;
        return false;
    }

    bool isCyclic()
    {
        map<T,bool> visited;
        map<T,bool> inStack;

        for(auto i : adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                bool cyclePresent = isCyclicHelper(node,visited,inStack);

                if(cyclePresent)
                    return true;
            }
        }

        return false;
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

    if(g.isCyclic())
        cout<<"Cycle is present"<<endl;
    else
        cout<<"Cycle is not present"<<endl;

    return 0;
}
