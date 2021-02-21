#include<iostream>
#include<vector>
using namespace std;

class edge
{
    public:

    int v=0;
    int w=0;

    edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

const int N=7;

vector<vector<edge>> graph(N);

void addEdge(int u, int v, int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));
}

void display()
{
    for(int i=0;i<N;i++)
    {
        cout<<to_string(i)+"->";
        for(edge e:graph[i])
        {
            cout<<"("+to_string(e.v)+","+to_string(e.w)+")";
        }
        cout<<endl;
    }
}

int findedge(int u, int v)
{
    int idx=-1;
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i].v==v) idx=i;
    }
    return idx;
}

void removeEdge(int u, int v)
{
    int idx1=findedge(u,v);
    int idx2=findedge(v,u);

    graph[u].erase(graph[u].begin()+idx1);
    graph[v].erase(graph[v].begin()+idx2);
}

void removeVtx(int u)
{
    for(int i=graph[u].size()-1;i>=0;i--)
    {
        int v=graph[u][i].v;
        removeEdge(u,v);
    }
}

bool hasPath(int src,int dest,vector<bool>& vis) //DFS
{
    if(src==dest) return true;

    vis[src]=true;
    bool res=false;
    for(edge e:graph[src])
    {
        if(!vis[e.v]) res=res||hasPath(e.v,dest,vis);
    }
    return res;
}

int printAllPath(int src, int dest,vector<bool>& vis,string psf)
{
    if(src==dest)
    {
        cout<<psf<<dest<<endl;
        return 1;
    }
    int count=0;
    vis[src]=true;
    for(edge e:graph[src])
    {
        if(!vis[e.v]) count+=printAllPath(e.v,dest,vis,psf+to_string(src)+" ");
    }
    vis[src]=false;
    return count;
}

class heavyPair{
    public:

    int weight=0;
    string path="";

    heavyPair(int weight,string path)
    {
        this->weight=weight;
        this->path=path;
    }
};

heavyPair heavyPath(int src, int dest,vector<bool>& vis)
{
    if(src==dest)
    {
        heavyPair base(0,to_string(src));
        return base;
    }
    vis[src]=true;
    heavyPair myAns(-1e8,"");
    for(edge e: graph[src])
    {
        heavyPair recAns=heavyPath(e.v,dest,vis);
        if(recAns.weight+e.w>myAns.weight)
        {
            myAns.weight=recAns.weight+e.w;
            myAns.path=to_string(src)+" "+recAns.path;
        }
    }
    vis[src]=false;
    return myAns;
}

void constructGraph()
{

    // for(int i =0;i<e;i++){
    //     int u,v,w; cin >> u >>v>>w;
    //     addEdge(u,v,w);
    // }

    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    // addEdge(0, 6, 3);
}

int main()
{
    constructGraph();
    // vector<bool> vis(N, false);
    // cout << printAllPath(0, 6, vis, "") << endl;
    hamintonialPathAndCycle(0);
    return 0;
}