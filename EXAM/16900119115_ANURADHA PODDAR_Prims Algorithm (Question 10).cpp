#include<iostream>
#include"16900119115_ANURADHA PODDAR_Priority Queue.cpp"
#include<fstream>
#define s 10
using namespace std;
int V;
int E;
int graph[s][s];
void input(){
    ifstream fp("Prims Input Matrix.txt");
    fp>>V;
    fp>>E;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            fp>>graph[i][j];
        }
    }
    fp.close();
    //Printing the adjacency matrix
    cout<<"The adjacency matrix is :\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Prims(){
    int key[V];
    int parent[V];
    bool MST[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        parent[i]=0;
        MST[i]=false;
    }
    key[0]=0;
    for(int i=0;i<V;i++)
        insertKey(key[i]);
    while(!isEmpty()){
        int u=extractMinimum();
        int x;
        for(x=0;x<V;x++){
            if(key[x]==u && MST[x]==false){
                break;
            }
        }
        MST[x]=true;
        for(int i=0;i<V;i++){
            if(graph[x][i]!=0 ){
                if(MST[i]==false && graph[x][i]<key[i]){
                    key[i]=graph[x][i];
                    decreaseKey(i,key[i]);
                    parent[i]=x;
                }
            }
        }
    }
    //Printing MST
    int total=0;
    cout<<"Minimum Spanning Tree is :\n";
    cout<<"Source      Dest.      Weight\n";
    for(int i=1;i<V;i++){
        if(i<parent[i])
            cout<<(char)(i+65)<<"           "<<(char)(parent[i]+65)<<"           "<<key[i]<<endl;
        else
            cout<<(char)(parent[i]+65)<<"           "<<(char)(i+65)<<"           "<<key[i]<<endl;
        total+=key[i];
    }
    cout<<"Total weight of MST = "<<total<<endl;
}
int main(){
    input();
    Prims();
}
