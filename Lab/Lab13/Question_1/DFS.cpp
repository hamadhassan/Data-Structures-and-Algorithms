#include <iostream>
using namespace std;
class Graph{
    public:
    int V;
    int E;
    int **adj;
    char *color;
    int *distance;
    int *parent;
    int time;
    Graph(int V,int E){
        this->V=V;
        this->E=E;
        this->adj=new int*[V];
        for(int i=0;i<V;i++){
            adj[i]=new int[V];
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=0;
            }
        }
    }
    ~Graph(){
        for(int i=0;i<V;i++){
            delete adj[i];
        }
        delete adj;
        delete color;
        delete distance;
        delete parent;
        this->adj=NULL;
        this->color=NULL;
        this->distance=NULL;
        this->parent=NULL;
    }
    void AddEdge(int u,int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void DFS(){
        color=new char[V];
        distance=new int[V];
        parent=new int[V];
        for(int i=0;i<V;i++){
            color[i]='W';
            distance[i]=0;
            parent[i]=-1;
        }
        time=0;
        for(int i=0;i<V;i++){
            if(color[i]=='W'){
                DFSVisit(i);
            }
        }
    }
    void DFSVisit(int u){
        color[u]='G';
        time++;
        distance[u]=time;
        for(int i=0;i<V;i++){
            if(adj[u][i]==1){
                if(color[i]=='W'){
                    parent[i]=u;
                    DFSVisit(i);
                }
            }
        }
        color[u]='B';
        time++;
        distance[u]=time;
    }
    void Print(){
        for(int i=0;i<V;i++){
            cout<<i<<" "<<color[i]<<" "<<distance[i]<<" "<<parent[i]<<endl;
        }
    }
    void TapologySort(){
        DFS();
        int *temp=new int[V];
        for(int i=0;i<V;i++){
            temp[i]=distance[i];
        }
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                if(temp[i]<temp[j]){
                    int t=temp[i];
                    temp[i]=temp[j];
                    temp[j]=t;
                }
            }
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(temp[i]==distance[j]){
                    cout<<j<<" ";
                }
            }
        }
        cout<<endl;
    }
    void StronglyConnectedComponents(){
        DFS();
        Graph *g=Transpose();
        g->DFS();
        int *temp=new int[V];
        for(int i=0;i<V;i++){
            temp[i]=g->distance[i];
        }
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                if(temp[i]<temp[j]){
                    int t=temp[i];
                    temp[i]=temp[j];
                    temp[j]=t;
                }
            }
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(temp[i]==g->distance[j]){
                    cout<<j<<" ";
                }
            }
        }
        cout<<endl;
    }
    Graph* Transpose(){
        Graph *g=new Graph(V,E);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    g->AddEdge(j,i);
                }
            }
        }
        return g;
    }
};
int main(){
    Graph g(6,6);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,3);
    g.AddEdge(1,4);
    g.AddEdge(2,5);
    g.AddEdge(2,4);
    g.DFS();
    g.Print();
    cout<<"---------------------"<<endl;
    g.TapologySort();
    cout<<"---------------------"<<endl;
    g.StronglyConnectedComponents();
    return 0;
}