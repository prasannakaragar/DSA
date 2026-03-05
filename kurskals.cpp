#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Edge{
    public:
    int u;
    int v;
    int wt;
    Edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
class Graph{
public:
vector<Edge>edges;
vector<int>rank;
vector<int>par;

int V;
Graph(int V){
    this->V=V;
    for(int i=0;i<V;i++){
        rank.push_back(0);
        par.push_back(i);
    }
}
int find(int x){
    if(par[x]==x){
        return x;
    }

    return par[x]=find(par[x]);
}
void unionbyRank(int u,int v){
    int paru=find(u);
    int parv=find(v);
    if(rank[paru]==rank[parv]){
        par[parv]=paru;
        rank[paru]++;
    }else if(rank[paru]>rank[parv]){
        par[parv]=paru;
    }else{
        par[paru]=parv;
    }
}
void addEdge(int u,int v,int wt){
    edges.push_back(Edge(u,v,wt));
}
void kurskals(){
sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){return a.wt<b.wt;});
int count=0;
int minCost=0;
for(int i=0;i<edges.size();i++){
    Edge e=edges[i];
   int paru=find(e.u);
   int parv=find(e.v);
    if(paru!=parv){
        unionbyRank(e.u,e.v);
        count++;
        minCost+=e.wt;
        
    }
}
    cout<<"Min Cost: "<<minCost;
}
};

int main(){

    Graph graph(4);
    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);
    graph.kurskals();
    return 0;
}