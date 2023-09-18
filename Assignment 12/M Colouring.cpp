#include<iostream>
#include<fstream>
#define s 10
using namespace std;
int V;
int graph[s][s];
int x[s];
int m;
static int c;
void input(){
    fstream fp("m coloring.txt");
    fp>>V;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            fp>>graph[i][j];
        }
    }
    fp.close();
    cout<<"Printing adjacency matrix\n";
     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Enter the maximum number of colors that can be used\n";
    cin>>m;
}
void print(){
    c++;
    for(int i=0;i<V;i++)
        cout<<x[i]<<"  ";
    cout<<endl;
}
void nextValue(int k){
    while(true){
        x[k]=(x[k]+1) % (m+1);
        if(x[k]==0)
            return;
        int j;
        for(j=0;j<k;j++){
            if(graph[k][j]==1 && x[j]==x[k])
                break;
        }
        if(j==k)
            return;
    }
}
void mColoring(int k){
    while(true){
        nextValue(k);
        if(x[k]==0)
            return;
        if(k==V-1)
            print();
        else
            mColoring(k+1);
    }
}
int main(){
    input();
    mColoring(0);
    if(c==0)
        cout<<"The graph is not "<<m<<" colorable\n";
    else
        cout<<"No. of possible solutions = "<<c<<endl;
}
