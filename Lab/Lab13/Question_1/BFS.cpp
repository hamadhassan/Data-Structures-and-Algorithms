#include <iostream>
using namespace std;
class Queue{
    public:
    int head;
    int tail;
    int size;
    int *arr;
    Queue(int size){
        this->size=size;
        this->head=0;
        this->tail=0;
        this->arr=new int[size];
    }
    ~Queue(){
        delete arr;
        this->arr=NULL;
    }
    void Enqueue(int data){
        if(tail==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[tail]=data;
            tail++;
        }
    }
    int Dequeue(){
        if(head==tail){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int temp=arr[head];
            head++;
            return temp;
        }
    }
};
class Graph{
    public:
    int V;
    int E;
    int **adj;
    char *color;
    int *distance;
    int *parent;
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
            this->adj[i]=NULL;
        }
        delete adj;
        this->adj=NULL;
    }
    void AddEdge(int u,int v){//undirected graph
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void BFS(int s){//s is the source vertex 
        color=new char[V];
        distance=new int[V];
        parent=new int[V];
        for(int i=0;i<V;i++){
            color[i]='W';
            distance[i]=INT_MAX;
            parent[i]=-1;
        }
        color[s]='G';
        distance[s]=0;
        parent[s]=-1;
        Queue q(V);
        q.Enqueue(s);
        while(q.head!=q.tail){
            int u=q.Dequeue();
            for(int i=0;i<V;i++){
                if(adj[u][i]==1 && color[i]=='W'){
                    color[i]='G';
                    distance[i]=distance[u]+1;
                    parent[i]=u;
                    q.Enqueue(i);
                }
            }
            color[u]='B';
        }
    }
    void PrintPath(int s,int v){
        if(s==v){
            cout<<s<<" ";
        }
        else if(parent[v]==-1){
            cout<<"No path from "<<s<<" to "<<v<<" exists"<<endl;
        }
        else{
            PrintPath(s,parent[v]);
            cout<<v<<" ";
        }
    }
};
int main(){
    Graph g(8,8);
    g.AddEdge(1,2);
    g.AddEdge(1,5);
    g.AddEdge(2,6);
    g.AddEdge(6,3);
    g.AddEdge(6,7);
    g.AddEdge(3,7);
    g.AddEdge(3,4);
    g.AddEdge(7,4);
    g.BFS(2);

    g.PrintPath(2,7);	
    return 0;
}
