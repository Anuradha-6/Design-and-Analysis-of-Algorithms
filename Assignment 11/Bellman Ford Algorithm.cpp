#include<iostream>
#include<fstream>
#define s 10
using namespace std;
class Edge{
public:
    int src;
    int dest;
    int wt;
};
Edge* edge;
int V;
int E;
int S;
void input(){
    ifstream fp("Bellman ford.txt");
    fp>>V;
    fp>>E;
    fp>>S;
    edge = new Edge[E];
    for(int i=0;i<E;i++){
        fp>>edge[i].src;
        fp>>edge[i].dest;
        fp>>edge[i].wt;
    }
    fp.close();
}
void bellmanFord(){
    int dist[V];
    int p[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        p[i]=INT_MAX;
    }
    dist[S]=0;
    for(int a=1;a<=V-1;a++){
        for(int i=0;i<E;i++){
            int u=edge[i].src;
            int v=edge[i].dest;
            if((dist[u]+edge[i].wt) < dist[v]){
                dist[v]= dist[u]+edge[i].wt;
                p[v]=u;
            }
        }
    }
    //Checking for negetive weight cycles
    for(int i=0;i<E;i++){
        int u=edge[i].src;
        int v=edge[i].dest;
        if(dist[u]+edge[i].wt < dist[v]){
            cout<<"Graph contains negetive weight cycle\n";
            exit(0);
        }
    }
    //Printing shortest path from source vertex.
    cout<<"Shortest path from source vertex is: \n";
    for(int i=0;i<V;i++){
        cout<<"Source      Dest.       Shortest path\n";
        char src=S+65;
        char d=i+65;
        cout<<src<<"           "<<d<<"           "<<dist[i]<<endl;
    }
}
int main(){
    input();
    bellmanFord();
}
