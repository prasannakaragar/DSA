#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
   int v;
   list<int>*l;
   bool isdir;
   public:
   Graph(int v,bool isdir=true){
    this->v=v;
    l= new list<int>[v];
    this->isdir=isdir;
   }

   void addEdge(int u,int v){
    l[u].push_back(v);
    if(isdir){
    l[v].push_back(u);
    }
   }
   void print(){
    for(int i=0;i<v;i++){
        list<int>neighbour=l[i];
        cout<<i<<":";
        
        for(int k:neighbour){
            cout<<k<<" ";
        }
        cout<<endl;
    }
   }
   void bfshelper(int u,vector<bool>&vis){
    queue<int>q;
    
    q.push(u);
    vis[u]=true;
    while(q.size()>0){
      int t=q.front();
      q.pop();
      cout<<t<<" ";
      list<int>curr=l[t];
      for(int k:curr){
        if(!vis[k]){
            vis[k]=true;
            q.push(k);
        }
      }
    }
    
   }
   void bfs(){
    vector<bool>vis(v,false);
      for(int i=0;i<v;i++){
        if(!vis[i]){
            bfshelper(i,vis);
            cout<<endl;
        }
      }
      cout<<endl;
   }
   void dfshelp(int u,vector<bool>&vis){
    cout<<u<<" ";
     vis[u]=true;
     list<int>neighbour=l[u];
     for(int V:neighbour){
        if(!vis[V]){
            dfshelp(V,vis);
        }
     }
    
   }
   void dfs(){
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfshelp(i,vis);
            cout<<endl;
        }
    }
    cout<<endl;
   }
   bool pathhelpdfs(int scr,int dest,vector<bool>&vis){
        if(scr==dest){
            return true;
        }
        
        vis[scr]=true;
        list<int>neighbour=l[scr];
        for(int k:neighbour){
            if(!vis[k]){
                if(pathhelpdfs(k,dest,vis)){
                    return true;
                }
            }
        }
        return false;

    }
    bool haspathdfs(int scr,int dest){
        vector<bool>vis(v,false);
        return pathhelpdfs(scr,dest,vis);
    }
   bool haspahtbfs(int scr,int dest){
    vector<bool>vis(v,false);
    queue<int>q;
    q.push(scr);
    vis[scr]=true;
    while(q.size()>0){

        int u=q.front();
        q.pop();
        if(u==dest){
            return true;
        }
        list<int>neighbour=l[u];
        for(int V:neighbour){
            if(!vis[V]){
                vis[V]=true;
                q.push(V);
            }
        }
    }
    return false;
   
   }
   bool isCyclehelper(int scr,int par,vector<bool>&vis){

    vis[scr]=true;
    list<int>neighbour=l[scr];
    for(int V:neighbour){
        if(!vis[V]){
            if(isCyclehelper(V,scr,vis)){
                return true;
            }
        }else{
            if(V!=par){
                return true;
            }
        }
    }
    return false;

   }
   bool isCycleexit(){
    vector<bool>vis(v,false);
    return isCyclehelper(0,-1,vis);
   }
   bool isBaipartait(){
    vector<bool>vis(v,false);
    queue<int>q;
        q.push(0);
        
        vector<int>color(v,-1);
        color[0]=0;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            vis[u]=true;
        list<int>neighbour=l[u];
        for(int V:neighbour){
            if(!vis[V]){
                vis[V]=true;
               color[V]=!color[u];
            }else{
                if(color[v]==color[u]){
                    return false;
                }
            }
        }
      }
        return true;
   }
   void printAllpathhelp(int src,int dest,vector<bool> &vis,string &path){
    if(src==dest){
        cout<<path<<dest<<endl;
        return;
    }
    vis[src]=true;
    path+=to_string(src);
    list<int>neighbour=l[src];
    for(int V:neighbour){
       if(!vis[V]){
        printAllpathhelp(V,dest,vis,path);
       }
    }
    path=path.substr(0,path.size()-1);
    vis[src]=false;
   }
   void printAllpath(int src,int dest){
    vector<bool>vis(v,false);
    string path="";
    printAllpathhelp(src,dest,vis,path);
   }
   void topohelp(int src,vector<bool>& vis,stack<int>& s){
         vis[src]=true;
         list<int>neighbour=l[src];
         for(int V:neighbour){
            if(!vis[V]){
                topohelp(V,vis,s);
            }
         }
         s.push(src);
   }
   void toposort(){
    vector<bool>vis(v,false);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topohelp(i,vis,s);
        }
    }
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }

   }
   void calcIndegree(vector<int>& indeg){
    for(int i=0;i<v;i++){
        list<int>neighbour=l[i];
        for(int V:neighbour){
            indeg[V]++;
        }
    }
   }
   
   void toposort1(){
    vector<int>indeg(v,0);
    calcIndegree(indeg);
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(q.size()>0){
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        list<int>neighbour=l[curr];
        for(int V:neighbour){
            indeg[V]--;
            if(indeg[V]==0){
                q.push(V);
            }
        }
    }
   cout<<endl;
   }
   void prinsAlgo(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>mst(v,false);
    pq.push(make_pair(0,src));
    while(pq.size()>0);
   }
   
   
};
int main(){
    Graph graph(6,false);
   graph.addEdge(2,3);
   graph.addEdge(3,1);
   graph.addEdge(4,0);
   graph.addEdge(4,1);
   graph.addEdge(5,0);
   graph.addEdge(5,2);
   

   graph.toposort1();
 
   

    return 0;
}