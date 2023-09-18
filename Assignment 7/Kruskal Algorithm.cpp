#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int src;
    int dest;
    int wt;
};
int V;
int E;
Edge* edge;
void input(){
    fstream fp("Kruskal input.txt");
    fp>>V;
    fp>>E;
    edge=new Edge[E];
    for(int i=0;i<E;i++){
        fp>>edge[i].src>>edge[i].dest>>edge[i].wt;
    }
    cout<<"The edges in the graph are:\n";
    cout<<"Source     Dest.      Weight\n";
    for(int i=0;i<E;i++){
        cout<<edge[i].src<<"          "<<edge[i].dest<<"          "<<edge[i].wt<<endl;
    }
}
int find(int v,int *parent){
    if(parent[v]==v)
        return v;
    return find(parent[v],parent);
}
bool compare(Edge e1,Edge e2){
    return (e1.wt<e2.wt);
}
void kruskal(){
    Edge *MST=new Edge[V-1];
    sort(edge, edge+E, compare);
    int *parent=new int[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    int count=0;;
    int i=0;
    while(count!= V-1){
        Edge current=edge[i];
        int sourceParent = find(current.src, parent);
        int destParent = find(current.dest, parent);
        if(sourceParent!=destParent){
            MST[count]=current;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    //Displaying MST
    cout<<"The edges included in MST are:\n";
    cout<<"Source    Dest.    Weight\n";
    for(int i=0;i<V-1;i++){
        if(MST[i].src < MST[i].dest)
            cout<<MST[i].src<<"         "<<MST[i].dest<<"        "<<MST[i].wt<<endl;
        else
            cout<<MST[i].dest<<"         "<<MST[i].src<<"       "<<MST[i].wt<<endl;
    }
}
int main(){
    input();
    kruskal();
}
