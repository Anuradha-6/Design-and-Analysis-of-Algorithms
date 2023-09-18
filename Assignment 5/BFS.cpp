#include<iostream>
#include"Queue.cpp"
#include<fstream>
#define size 10
using namespace std;
class BFS{
public:
    int v;
    int mat[size][size];
    int visited[];
    BFS(){
        ifstream fp("inputmat.txt");
        fp>>v;
        visited[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                fp>>mat[i][j];
            }
        }
        fp.close();
        cout<<"Printing the adjacency matrix:\n";
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(char s){
        Queue ob;
        for(int i=0;i<v;i++)
            visited[i]=0;
        ob.enQueue(s);
        visited[(int)s-65]=1;
        while(!ob.isEmpty()){
            char x=ob.deQueue();
            s=x;
            cout<<x<<"  ";
            for(int i=0;i<v;i++){
                if(mat[(int)s-65][i]==1 && visited[i]==0){
                    visited[i]=1;
                    ob.enQueue(char(i+65));
                }
            }
        }
    }
};
int main(){
    BFS obj;
    char a;
    cout<<"Enter starting vertex\n";
    cin>>a;
    obj.bfs(a);
}
