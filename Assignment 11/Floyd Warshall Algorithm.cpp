#include<iostream>
#include<fstream>
#define s 5
using namespace std;
int V;
int graph[s][s];
int d[s][s];
int p[s][s];
void input(){
    ifstream fp("Floyd Warshall.txt");
    fp>>V;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            fp>>graph[i][j];
    fp.close();
    cout<<"Printing the adjacency matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void shortestPath(int i,int j){
    if(i==j)
        cout<<i+1<<" ";
    else if(p[i][j]==-999)
        cout<<"No path exists\n";
    else{
        shortestPath(i,p[i][j]);
        cout<<j+1<<" ";
    }
}
void floydWarshall(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==0 && i!=j)
                d[i][j]=INT_MAX;
            else
                d[i][j]=graph[i][j];
            if(d[i][j]==0 || d[i][j]==INT_MAX)
                p[i][j]=-999;
            else
                p[i][j]=i;
        }
    }
    cout<<"D0 : "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(d[i][j]==INT_MAX)
                cout<<"INF ";
            else
                cout<<d[i][j]<<"  ";
        }
        cout<<endl;
    }
    //Implementing Floyd Warshall Algorithm
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(d[i][j] > (d[i][k]+d[k][j]) && d[i][k]!=INT_MAX && d[k][j]!=INT_MAX){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
        cout<<"D"<<k+1<<" : "<<endl;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(d[i][j]==INT_MAX)
                    cout<<"INF ";
                else
                    cout<<d[i][j]<<"  ";
        }
        cout<<endl;
    }
    }
}
int main(){
    input();
    floydWarshall();
    int src;
    int dest;
    cout<<"Enter source vertex: \n";
    cin>>src;
    cout<<"Enter destination vertex\n";
    cin>>dest;
    cout<<"Shortest Path : ";
    shortestPath(src-1,dest-1);
    cout<<endl;
    cout<<"Cost of shortest path: "<<d[src-1][dest-1]<<endl;
}
